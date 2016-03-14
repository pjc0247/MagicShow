#pragma once

#include "cocos2d.h"

#include <mutex>
#include <thread>
#include <queue>

namespace pubnub {
	class context;
}

class NetworkNode : public cocos2d::Node
{
public:
	static NetworkNode *create(
		pubnub::context *pb,
		const std::string &channel);

protected:
	bool initialize(
		pubnub::context *pb,
		const std::string &channel);
	void onExit();

	void cleanup();

	void update(float dt);
	void subscriber();

private:
	bool isRunning;

	std::string channel;
	std::thread worker;
	pubnub::context *pb;

	std::mutex mutex;
	std::queue<std::string> packets;
};

