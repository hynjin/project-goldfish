#include "stacksADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mData{
	int Branch;
	int Row;
	int Column;
}mData;//������ ��ǥ�� �귻ġ�� �����ϱ� ���� ����ü

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