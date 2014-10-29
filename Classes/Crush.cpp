#include "Crush.h"

Crush:: Crush()
{
	row=19;
	col=10;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	map = new Rect *[col];
	for(int i=0;i<col;i++)
	{
		map[i] = new Rect[row];
		for(int j=0;j<row;j++)
		{
			map[i][j] = Rect(i*60,j*60,60,60);
		}
	}
}

bool Crush :: check(Rect guest)
{
	/*if(ghost.intersectsRect(guest))
	{
		CCLOG("%@#@!@#@#%$#%$%#$%");
	}*/
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			if(map[i][j].intersectsRect(guest))
				CCLOG("guest row :%d col :%d",i,j);
			
		}
	}
	return true;
}

Rect** Crush :: getMap()
{
	return map;
}

/*#include "Crush.h"
/*
bool Crush :: init()
{
	/*
	auto listener = EventListenerTouchAllAtOnce :: create();
    //listener->setSwallowTouches(true); //멀티터치이기 때문에 삼키면 안된다
	//listener->onTouchesBegan = CC_CALLBACK_2(Crush::onTouchesBegan, this);
	//EventDispatcher:: getInstance()->addEventListenerWithFixedPriority(listener, 1);
	
 
    listener->onTouchesBegan = CC_CALLBACK_2(Crush::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(Crush::onTouchesMoved, this);
    listener->onTouchesCancelled = CC_CALLBACK_2(Crush::onTouchesCancelled, this);
    listener->onTouchesEnded = CC_CALLBACK_2(Crush::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
 /*
	if ( CCLayer::init() )
	{

		if (! CCLayerColor::initWithColor( ccc4(255,255,255,255) ) )
		{
			return false;
		}

			this->setTouchEnabled(true);
	}
	

	return true;
}*/
/*
 void Crush::onTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCTouch* touch = (CCTouch*)( touches->anyObject() );
    CCPoint location = touch->getLocation();
	
	location = CCDirector::sharedDirector()->convertToGL(location);

	CCLOG("%@#@!@#@#%$#%$%#$%");
}
*/
 /*
void Crush::onTouchesBegan(const std::vector<Touch*>&touches, Event* unused_event){
 
    //...
 
    for (auto iter = touches.begin(); iter != touches.end(); iter++){
      Point location = (*iter)->getLocation();
      addNewSpriteAtPosition(location);
    }
 
    //...
 
}
 
void Crush::onTouchesMoved(const std::vector<Touch*>&touches, Event* unused_event){}
 
void Crush::onTouchesCancelled(const std::vector<Touch*>&touches, Event* unused_event){}
 
void Crush::onTouchesEnded(const std::vector<Touch*>&touches, Event* unused_event){}
*/
/*
bool Crush :: check(Rect ghost,Rect guest)
{
	if(ghost.intersectsRect(guest))
	{// 두 영역이 교차되어 있는 경우
		//CCLOG("%@#@!@#@#%$#%$%#$%");
	}
	return true;//충돌
}
*/
/*
void Crush ::onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *event)
{
   std::vector<Touch *>::const_iterator it = touches.begin();
   Touch *touch;
   Point location[2];
    
   for (int i=0; i<touches.size(); i++) {
       touch = (Touch *)(*it);
       location[i] = touch->getLocation();
       it++;
        
       CCLOG("location[%d] x=%f, y=%f", i, location[i].x, location[i].y);
   }
}*/
