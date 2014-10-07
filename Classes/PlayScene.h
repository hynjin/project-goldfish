#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "ManageGhost.h"
#include "CheckCrush.h"
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
	
	
	Find find;
	STACK* Stack;
	mData* data;
	CheckCrush crush;
	Rect ghost;
	Rect guest;

	cocos2d::Sprite *img;
	cocos2d::Sprite *zombi;
	cocos2d::CCObject *Sender;
	//ManageGhost ghost;

    CREATE_FUNC(PlayScene);
};

#endif //#define __PLAY_SCENE_H__
