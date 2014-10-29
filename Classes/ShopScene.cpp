#include "ShopScene.h"


Scene* ShopScene::createScene()
{
	// * Scene ����
	auto scene = Scene::create();

	// * �ٴ� ����
	ShopScene *layer = ShopScene::create();
	scene->addChild(layer);

	return scene;

}

// * scene transition
void ShopScene::TransitionScene(float delta)
{
	//Scene *nextScene = TransitionCrossFade::create(0.3,)
}



bool ShopScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}

	Sprite *spr = Sprite::create("goShop.png");
	spr->setAnchorPoint(Point::ZERO);
	spr->setPosition(Point(0, 0));
	this->addChild(spr);

}