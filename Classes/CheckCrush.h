#ifndef __CHECK_CRUSH_H__
#define __CHECK_CRUSH_H__

#include "cocos2d.h"

USING_NS_CC;

class CheckCrush
{
public:
    virtual bool init();
	bool check(Rect,Rect);

    //CREATE_FUNC(CheckCrush);
};

#endif //#define __CHECK_CRUSH_H__
