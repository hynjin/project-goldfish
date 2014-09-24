#include "stacksADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mData{
	int Branch;
	int Row;
	int Column;
}mData;//현재의 좌표와 브렌치를 저장하기 위한 구조체

class Find
{
public:
    STACK* stack;
	STACK* temp;
	mData* data;
	void Findmase();
	STACK* Send();
	mData* Dsend();
	void Check(int &x,int &y);
};