#include "StartScene.h"
#include "MainScene.h"

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	StartScene *layer = StartScene::create();
	scene->addChild(layer);

	return scene;
}

void StartScene::goMain(cocos2d::Ref* pSender)
{
	Scene *NextScene = MainScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}

bool StartScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}
	unscheduleAllSelectors();

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("start_background.png");
	logo->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	this->addChild(logo);
	
	auto mainButton = MenuItemImage::create(
											"start_startButton_u.png",
											"start_startButton_s.png",
											CC_CALLBACK_1(StartScene::goMain, this));
	mainButton->setPosition(Point(0, 300 ));
	auto *menu = Menu::create(mainButton,NULL);
	this->addChild(menu,1);

	return true;
}