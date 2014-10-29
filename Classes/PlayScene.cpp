#include "PlayScene.h"
#include "MainScene.h"

//���� gamescene�� �����ؾ� �ϴ� �κ�����
//�޴� ��ư ���� ���� gamescene�� ��ħ->���� ����

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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto Sender = CCObject::getReferenceCount();
	this->schedule(schedule_selector(PlayScene::Action),1.0);
	this->schedule(schedule_selector(PlayScene::GameUpdate));
	find.Findmase();
	Stack = find.Send();
	

	//���
	auto Back = Sprite::create("back.png");
	//Back->setAnchorPoint(Point(0.0,1.0));
	Back->setTextureRect(CCRectMake(0,0,1200,600));
	Back->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f ) );
	this->addChild(Back, 0);

	//��
	auto map = Sprite::create("level1.png");
	//map->setAnchorPoint(Point(0.0,0.0));
	map->setTextureRect(CCRectMake(0,0,540,420));
	map->setPosition(Point( visibleSize.width*0.5f, visibleSize.height*0.5f) );
	this->addChild(map, 0);
	
	//ĳ����
	girl = Sprite::create("girl.png",Rect(0,0,100,110));
	//map->setAnchorPoint(Point(0.0,0.0));
	girl->setPosition(Point(visibleSize.width*0.5f+1*60,visibleSize.height*0.5f+0*60));
	this->addChild(girl, 0);
	guest = Rect(girl->getPositionX(),girl->getPositionY(),100,110);
	//auto ghost = ManageGhost::create();

	//�ͽ�
	zombi = Sprite::create("zombi.png",Rect(0,0,100,110));
	zombi->setPosition(Point(visibleSize.width*0.5f+3*60,visibleSize.height*0.5f+1*60));//(Point(140,140));
	this->addChild(zombi,0);
	ghost = Rect(zombi->getPositionX(),zombi->getPositionY(),200,220);
	
	//��ư
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
{//�̵��� �� �ִ� ���� ã�Ƽ� ��ư�� ���� ������ �̵������� �� �� ������� �̵�

	CCActionInterval* myAction;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if(!emptyStack(Stack))
	{
		data=(mData*)stackTop(Stack);
		myAction = MoveTo::create(1,Point(visibleSize.width*0.5f+data->Column*60,visibleSize.height*0.5f+data->Row*60));
		girl->runAction(myAction);
		free(popStack(Stack));//������ ������ ����
	}

	CCLOG("Action!!");
}

void PlayScene :: GameUpdate(float f)
{
	guest = Rect(girl->getPositionX()+20,girl->getPositionY()+40,60,60);
	ghost = Rect(zombi->getPositionX(),zombi->getPositionY(),200,220);

	crush.check(guest);
}