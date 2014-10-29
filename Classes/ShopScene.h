#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ShopScene : public Layer
{
public:
	static cocos2d::Scene* createScene();
	void TransitionScene(float delta);
	virtual bool init();
	CREATE_FUNC(ShopScene);
};

#endif //__SHOP_SCENE_H__
