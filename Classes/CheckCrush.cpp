#include "CheckCrush.h"

bool CheckCrush::init()
{

	return true;
}

bool CheckCrush :: check(Rect ghost,Rect guest)
{
	if(ghost.intersectsRect(guest))
	{// �� ������ �����Ǿ� �ִ� ���
		CCLOG("%@#@!@#@#%$#%$%#$%");
	}
	return true;//�浹
}