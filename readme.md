MagicShow
====
![magicman](img/magicman.png)
<br>
__API ������ ����ġ�� ����, ����, ������ ������__
<br>
__MagicShow__�� ���� ������Ÿ���� ������ �־ �������� ȿ�� ����/�׽�Ʈ�� ġƮŰ/�� ������ ���� �����ݴϴ�.<br>
���׸��� �� �ϳ� �ٲ�ٰ� ���ٰ� �ٽ� �������� ������.
<br>
__No server/host setup required__

Demo
----
![ui](img/ui.gif)
<br><br>
__�� �����ϱ�___<br>
![value](img/value.gif)
<br><br>
__�׼� ����ġ__<br>
![switch](img/switch.gif)

Supported Engine
----
* __cocos2d-x__

Todo
----
* Unity : ����Ƽ�� ��� �ɵ�

API
----
```json
{
  "TAB_NAME" : {
  },
  "BATTLE" : {
  },
  "SHOP" : {
  }
}
```

```cpp
class MyGameObject : Magic::Listener {
public:
  virtual void onConfigurationChanged() {
    /* impl */
  }
}
```