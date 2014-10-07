#include "CheckCrush.h"

bool CheckCrush::init()
{

	return true;
}

bool CheckCrush :: check(Rect ghost,Rect guest)
{
	if(ghost.intersectsRect(guest))
	{// 두 영역이 교차되어 있는 경우
		CCLOG("%@#@!@#@#%$#%$%#$%");
	}
	return true;//충돌
}