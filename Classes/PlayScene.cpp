#include "PlayScene.h"
#include "MainScene.h"

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	PlayScene *layer = PlayScene::create();
	scene->addChild(layer);

	return scene;
}

void PlayScene::BackToMain(cocos2d::Ref* pSender)
{
	Scene *NextScene = MainScene::createScene();
	Director::getInstance()->replaceScene(NextScene);
}

bool PlayScene::init()
{
	if( !Layer::init() )
	{
		return false;
	}
//	auto winSize = Director::sharedDirector()->getWinSize();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto Sender = CCObject::getReferenceCount();
	this->schedule(schedule_selector(PlayScene::callEveryFrame));
	find.Findmase();
	Stack = find.Send();
	data=(mData*)stackTop(Stack);

	//배경
	auto Back = Sprite::create("back.png");
	//Back->setAnchorPoint(Point(0.0,1.0));
	Back->setTextureRect(CCRectMake(0,0,1200,600));
	Back->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	this->addChild(Back, 0);
	//맵
	auto map = Sprite::create("level1.png");
	//map->setAnchorPoint(Point(0.0,0.0));
	map->setTextureRect(CCRectMake(0,0,540,420));
	map->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f) );
	this->addChild(map, 0);
	//캐릭터
	auto img = Sprite::create("img.png",Rect(0,0,100,110));
	//map->setAnchorPoint(Point(0.0,0.0));
	//img->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f) );
	img->setPosition(Point(visibleSize.width*0.5f+data->Column*32,visibleSize.height*0.5f+data->Row*32));
	this->addChild(img, 0);
	//버튼
	auto BackToMain = MenuItemImage::create(
											"main_startButton_u.png",
											"main_startButton_s.png",
											CC_CALLBACK_1(PlayScene::BackToMain, this));

	auto *button = Menu::create(BackToMain, NULL);
	button->setPosition(Point( visibleSize.width, visibleSize.height) );
	this->addChild(button,1);
	return true;
}

void PlayScene :: callEveryFrame(float f)
{
	//if(img->getPosition().x==data->Column*60&&img->getPosition().y==data->Row*60)
	//	doAction(Sender);
}
void PlayScene :: doAction(CCObject* pSender)
{
	
	if(!emptyStack(Stack))
	{
		data=(mData*)stackTop(Stack);
		CCActionInterval* myAction = CCMoveTo::create(2,Point(data->Column*60,data->Row*60));
		img->runAction(myAction);
		free(popStack(Stack));//스택의 데이터 삭제
	}
	

}