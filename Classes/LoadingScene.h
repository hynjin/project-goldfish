#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
	void transitionScene(float delta);
    virtual bool init();  	
    CREATE_FUNC(LoadingScene);
};

#endif //__LOADING_SCENE_H__
