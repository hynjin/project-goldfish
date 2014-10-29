#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
	void BackToMain(cocos2d::Ref* pSender);
	void goPlay(cocos2d::Ref* pSender);
	void goQuit(cocos2d::Ref* pSender);
	void goShop(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
};

#endif //#define __GAME_SCENE_H__
