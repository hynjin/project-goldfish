#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "ManageGhost.h"
#include "Crush.h"
//#include "FindRoad.h"
USING_NS_CC;

class PlayScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void BackToMain(cocos2d::Ref* pSender);
	void Action(float f);
	void callEveryFrame(float f);
	void GameUpdate(float f);
	
	Crush crush;
	Find find;
	STACK* Stack;
	mData* data;
	Rect ghost;
	Rect guest;

	cocos2d::Sprite *girl;
	cocos2d::Sprite *zombi;
	cocos2d::CCObject *Sender;
	//ManageGhost ghost;

    CREATE_FUNC(PlayScene);
};

#endif //#define __PLAY_SCENE_H__
