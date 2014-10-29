#include "ManageGhost.h"
Scene* ManageGhost::createScene()
{
	auto scene = Scene::create();
	ManageGhost *layer = ManageGhost::create();
	scene->addChild(layer);

	return scene;
}
bool ManageGhost::init()
{

	if( !Layer::init() )
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto Sender = CCObject::getReferenceCount();

	find.Findmase();
	Stack = find.Send();

	//좀비
	zombi = Sprite::create("zombi.png",Rect(0,0,100,110));
	//map->setAnchorPoint(Point(0.0,0.0));
	zombi->setPosition(Point(visibleSize.width*0.5f+1*60,visibleSize.height*0.5f+0*60));(Point( visibleSize.width*0.5f, visibleSize.height*0.5f));
	this->addChild(zombi, 0);
	
	//버튼

	CCMenuItemFont* pMenuItem = CCMenuItemFont::create(
		"Action",
		this,
		menu_selector(ManageGhost::doAction));
		
	pMenuItem->setColor(ccc3(0,0,0));
	CCMenu* pMenu = CCMenu :: create(pMenuItem,NULL);
	pMenu ->alignItemsHorizontally();
	pMenu->setPosition(visibleSize.width*0.5f+10, visibleSize.height*0.5f+10);
	this->addChild(pMenu);

	return true;
}


void ManageGhost :: doAction(CCObject* pSender)
{//이동할 수 있는 길을 찾아서 버튼을 누를 때마다 이동가능한 길 중 갈림길로 이동

	CCActionInterval* myAction;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if(!emptyStack(Stack))
	{
		data=(mData*)stackTop(Stack);
		CCLOG("%d\t%d\n", data->Row,data->Column);
		myAction = MoveTo::create(1,Point(visibleSize.width*0.5f+data->Column*60,visibleSize.height*0.5f+data->Row*60));
		zombi->runAction(myAction);
		free(popStack(Stack));//스택의 데이터 삭제
	}

	CCLOG("!!");
}