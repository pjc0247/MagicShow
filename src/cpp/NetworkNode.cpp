#include "stdafx.h"

#include "NetworkNode.h"
#include "Configs.h"
#include "pubnub.hpp"

using namespace std;
using namespace cocos2d;

NetworkNode *NetworkNode::create(
	pubnub::context *pb,
	const string &channel)
{
	NetworkNode *b = new NetworkNode();
	if (b && b->initialize(pb, channel)) {
		b->autorelease();
		return b;
	}
	CC_SAFE_DELETE(b);
	return nullptr;
}

bool NetworkNode::initialize(
	pubnub::context *pb,
	const string &channel)
{
    if ( !Node::init() )
        return false;
	
	this->channel = channel;
	this->pb = pb;

	scheduleUpdate();

	worker = std::move(std::thread([=]() {
		isRunning = true;

		subscriber();
	}));

    return true;
}

void NetworkNode::onExit() {
	cleanup();
}
void NetworkNode::cleanup() {
	if (worker.joinable()) {
		isRunning = false;
		worker.join();
	}
}

void NetworkNode::update(float dt) {
	std::lock_guard<std::mutex> guard(mutex);
	while (packets.empty() == false) {
		auto &packet = packets.front();
		packets.pop();

		Configs::update(packet);
	}
}

void NetworkNode::subscriber() {
	while (true) {
		pubnub_res res;
		auto future = pb->subscribe(channel);

		future.start_await();
		while (future.is_ready() == false) {
			this_thread::sleep_for(
				chrono::milliseconds(100));

			if (isRunning == false)
				return;
		}
		res = future.end_await();

		if (res == PNR_OK) {
			auto msgs = pb->get_all();

			lock_guard<::mutex> guard(mutex);
			for (auto &msg : msgs) {
				packets.push(msg);
			}
		}
		else {
			cout << "Error" << endl;

			// break ?
		}
	}
}
