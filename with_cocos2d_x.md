cocos2d-x 에서 사용하기
=====

```cpp
pb = new pubnub::context(
		"PUBNUB_PUBLISH_KEY",
		"PUBNUB_SUBSCRIBE_KEY");

// 내부적으로 4자리 숫자 채널 키를 랜덤 생성합니다.
//   화면 좌측 하단에 채널 이름이 표시됩니다.
addChild(NetworkNode::create(pb));

// 또는 직접 채널 이름을 지정할 수 있습니다.
//    이 경우 채널 이름 라벨은 생성되지 않습니다.
addChild(NetworkNode::create(pb, "CHANNEL_NAME"));
```


__bind__ 사용하기
----
```c++
$bind(on_jump, [this](){
  this->jump();
});
```
