#ifndef __CRUSH_H__
#define __CRUSH_H__

#include "cocos2d.h"

USING_NS_CC;

class Crush
{
public:
   // virtual bool init();
	Crush();
	bool check(Rect);
	Rect** getMap();

private:
	Rect **map;
	int row,col;

};

#endif //#define __CRUSH_H__



/*#ifndef __CRUSH_H__
#define __CRUSH_H__

#include "cocos2d.h"
#include "PlayScene.h"

USING_NS_CC;

//Ãæµ¹ °Ë»ç & ¼Õ´Ô ³î·¡Å°±â 
class Crush : public CCLayer
{
public:
	//bool init();
	bool check(Rect,Rect);
	/*
protected:
	virtual void onTouchesBegan(CCSet* touches, CCEvent* event);
	
	virtual void onTouchesBegan(const std::vector<Touch*>&touches, Event* unused_event);
    virtual void onTouchesMoved(const std::vector<Touch*>&touches, Event* unused_event);
    virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event* unused_event);
    virtual void onTouchesEnded(const std::vector<Touch*>&touches, Event *unused_event);*/
//};

//#endif //#define __CRUSH_H__
//*/
