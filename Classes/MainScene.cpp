#include "MainScene.h"
#include "GameScene.h"

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	MainScene *layer = MainScene::create();
	scene->addChild(layer);

	return scene;
}

void MainScene::goPlay(cocos2d::Ref* pSender)
{
	Scene *NextScene = GameScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}


bool MainScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("main_background.png");
	logo->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	this->addChild(logo);
	
	auto playButton = MenuItemImage::create(
											"main_startButton_u.png",
											"main_startButton_s.png",
											CC_CALLBACK_1(MainScene::goPlay, this));
	playButton->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	auto *menu = Menu::create(playButton,NULL);
	this->addChild(menu,1);




	return true;
}