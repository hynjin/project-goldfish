#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "FindRoad.h"
USING_NS_CC;

class PlayScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void BackToMain(cocos2d::Ref* pSender);
	void doAction(CCObject* pSender);
	void callEveryFrame(float f);

	Find find;
	STACK* Stack;
	mData* data;


	cocos2d::Sprite *img;
	cocos2d::CCObject *Sender;
    CREATE_FUNC(PlayScene);
};

#endif //#define __GAME_SCENE_H__
