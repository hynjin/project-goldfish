#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
	void goPlay(cocos2d::Ref* pSender);
    CREATE_FUNC(MainScene);
};

#endif //__MAIN_SCENE_H__
