#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class StartScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
	void goMain(cocos2d::Ref* pSender);
    virtual bool init();  
    CREATE_FUNC(StartScene);
};

#endif //#define __START_SCENE_H__
