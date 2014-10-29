#include "GameScene.h"
#include "MainScene.h"
#include "PlayScene.h"

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	GameScene *layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

void GameScene::BackToMain(cocos2d::Ref* pSender)
{
	Scene *NextScene = MainScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}

void GameScene::goPlay(cocos2d::Ref* pSender)
{
	Scene *NextScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}

void GameScene::goQuit(cocos2d::Ref* pSender)
{
	 Director::getInstance()->end();
    exit(0);
}
void GameScene::goShop(cocos2d::Ref* pSender )
{
	Scene *NextScene = ShopScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}

bool GameScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto goPlay = MenuItemImage::create(
											"start_startButton_u.png",
											"start_startButton_s.png",
											CC_CALLBACK_1(GameScene::goPlay, this));

	auto BackToMain = MenuItemImage::create(
											"main_startButton_u.png",
											"main_startButton_s.png",
											CC_CALLBACK_1(GameScene::BackToMain, this));
	auto goQuit = MenuItemImage::create(
											"CloseNormal.png",
											"CloseSelected.png",
											CC_CALLBACK_1(GameScene::goQuit, this));
	auto goShop = MenuItemImage::create(
											"goShop.png",
											"goShop.png",
											CC_CALLBACK_1(GameScene::goShop, this));

	auto *menu = Menu::create(goPlay, BackToMain, goQuit, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);



	return true;
}