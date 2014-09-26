#include "LoadingScene.h"
#include "StartScene.h"

Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();
	LoadingScene *layer = LoadingScene::create();
	scene->addChild(layer);

	return scene;
}

void  LoadingScene::transitionScene(float delta)
{
	Scene *nextScene = TransitionCrossFade::create(0.2,StartScene::createScene());
	Director::getInstance()->replaceScene(nextScene);
}

bool LoadingScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("team_logo.png");
	logo->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	this->addChild(logo);

	this->schedule(schedule_selector(LoadingScene::transitionScene), 1.5);
	return true;
}