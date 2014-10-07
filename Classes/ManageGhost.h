#ifndef __MANAGE_GHOST_H__
#define __MANAGE_GHOST_H__

#include "cocos2d.h"
#include "FindRoad.h"

USING_NS_CC;

class ManageGhost : public Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void doAction(CCObject* pSender);

    CREATE_FUNC(ManageGhost);
private:
	cocos2d::Sprite *zombi;
	cocos2d::CCObject *Sender;

	
	Find find;
	STACK* Stack;
	mData* data;

};

#endif //#define __MANAGE_GHOST_H__
