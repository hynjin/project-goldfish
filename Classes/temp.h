#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class temp : public cocos2d::CCLayerColor
{
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	void menuCloseCallback(CCObject* pSender);

	virtual void onTouchesBegan(CCSet* touches, CCEvent* event);
	virtual void onTouchesEnded(CCSet* touches,CCEvent* event);

	CREATE_FUNC(temp);
};