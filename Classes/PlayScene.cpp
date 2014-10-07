#include "PlayScene.h"
#include "MainScene.h"

//추후 gamescene과 통합해야 하는 부분있음
//메뉴 버튼 같은 경우는 gamescene과 겹침->추후 삭제

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
	this->schedule(schedule_selector(PlayScene::Action),1.0);
	this->schedule(schedule_selector(PlayScene::GameUpdate));
	find.Findmase();
	Stack = find.Send();
	

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
	img = Sprite::create("img.png",Rect(0,0,100,110));
	//map->setAnchorPoint(Point(0.0,0.0));
	img->setPosition(Point(visibleSize.width*0.5f+1*60,visibleSize.height*0.5f+0*60));
	this->addChild(img, 0);
	guest = Rect(img->getPositionX(),img->getPositionY(),100,110);
	//auto ghost = ManageGhost::create();

	//귀신
	zombi = Sprite::create("zombi.png",Rect(0,0,100,110));
	zombi->setPosition(Point(visibleSize.width*0.5f+3*60,visibleSize.height*0.5f+1*60));//(Point(140,140));
	this->addChild(zombi,0);
	ghost = Rect(zombi->getPositionX(),zombi->getPositionY(),200,220);
	
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

void PlayScene :: Action(float f)
{//이동할 수 있는 길을 찾아서 버튼을 누를 때마다 이동가능한 길 중 갈림길로 이동

	CCActionInterval* myAction;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if(!emptyStack(Stack))
	{
		data=(mData*)stackTop(Stack);
		CCLOG("%d\t%d\n", data->Row,data->Column);
		myAction = MoveTo::create(1,Point(visibleSize.width*0.5f+data->Column*60,visibleSize.height*0.5f+data->Row*60));
		img->runAction(myAction);
		free(popStack(Stack));//스택의 데이터 삭제
	}

	CCLOG("!!");
}

void PlayScene :: GameUpdate(float f)
{
	guest = Rect(img->getPositionX(),img->getPositionY(),100,110);
	ghost = Rect(zombi->getPositionX(),zombi->getPositionY(),200,220);

	crush.check(ghost,guest);
	CCLOG("%d,%d",img->getPositionX(),img->getPositionY());
}