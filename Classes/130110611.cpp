#include "13011061.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Find :: Findmase()
{
    int PossibleMove=0;
    int cRow,cColumn,cBranch;
    int i,j;//for���� ���
	int x,y;//�迭 Ȯ�ο� ���
	int ss,dd;//������,������ Ȯ�ο� ���
	char ArrMase[6][6]; // dat ������ �о mase�� �����ϱ� ���� �迭
    FILE *fp;
    STACK* stack;
	mData* infor;//����,��,�� ���� = dataPtr
	mData* check;//������ Ȯ��
    stack=createStack();
	temp=createStack();
    cRow=cColumn=i=j=x=y=ss=dd=0;
    
    if((fp=fopen("mase.txt", "r")) == NULL)//���� ����
	{
       // puts("file open error: Cannot find mase.txt");
        exit(0);
    }
	
	for(i=0;i<5;i++)//���Ͼ��� ���� �о� �迭�� ����
	{
			fscanf(fp,"%s",&ArrMase[i]);
	}
	fclose(fp);

	for(i=0;i<5;i++)//source ã��
	{
		for(j=0;j<5;j++)
		{
			if(ArrMase[i][j]=='S')//������ ã��
			{
				cRow=i;//���� ��ǥ����
				cColumn=j;
				ss=1;//�������� ã������ ǥ��
			}
			if(ArrMase[i][j]=='D')//������ ã��
				dd=1;
		}
	}
	if(ss!=1 || dd!=1)//�������� ã�� ���Ѱ��
	{
		//printf("������ Ȥ�� �������� ã�� �� �����ϴ�.\n");
		exit(1);
	}
	
	while(ArrMase[cRow][cColumn]!='D')//���� ��ġ�� �������� �ƴҰ��
	{
		x=cRow;//���� ��ġ�� ���� ���� ����
		y=cColumn;
		PossibleMove = 0;
		if((ArrMase[x+1][y]=='0' || ArrMase[x+1][y]=='D') && cRow!=4)//�Ʒ��� �̵� ������ �� Ȯ��
		{
			cRow=x+1;
			cColumn=y;
			PossibleMove++;
		}	
		if((ArrMase[x-1][y]=='0' || ArrMase[x-1][y]=='D') && cRow != 0)//����
		{
			cRow=x-1;
			cColumn=y;
			PossibleMove++;
		}
		if((ArrMase[x][y-1]=='0' || ArrMase[x][y-1]=='D') && cColumn != 0)//����
		{
			cRow=x;
			cColumn=y-1;
			PossibleMove++;
		}
		if((ArrMase[x][y+1]=='0' || ArrMase[x][y+1]=='D') && cColumn != 4)//����
		{
			cRow=x;
			cColumn=y+1;
			PossibleMove++;
		}
		if(PossibleMove !=0)//�̵������� ���
		{
			cBranch=PossibleMove-1;//push�� �� �����ϰ� branch�� ����
			if(ArrMase[cRow][cColumn]!='D')//���� ��ġ�� �������� �ƴҰ��
				ArrMase[cRow][cColumn]='X';//��ȴ� ������ ǥ��
			if(!fullStack(stack))//�� �� �������� Ȯ��
			{
				infor = (mData*)malloc(sizeof(mData));
				infor->Branch=cBranch;
				infor->Row=x;
				infor->Column=y;
				pushStack(stack,(void*)infor);//���� �߰�
			}
		}
		else//�̵� �Ұ����� ���
		{
			check = (mData*)stackTop(stack);//Top�� ������ �ҷ���
			cRow = check->Row;
			cColumn = check->Column;
			cBranch = check->Branch;
			while(cBranch == 0)//���� ���������� pop
			{
				if(!emptyStack(stack))//�� �������� Ȯ��
				{
					check = (mData*)popStack(stack);//���� ����
					cRow = check->Row;
					cColumn = check->Column;
					cBranch = check->Branch;
					free(check);//dataPtr ����
				}
				else//������ ���� ��� ����
				{
				//	printf("���� ã�� �� �����ϴ�.\n");
					exit(0);
				}
			}
		}
	}	
		
	//������ ����
	while(!emptyStack(stack))//�� �������� Ȯ��
	{
		data = (mData*)stackTop(stack);//chack�� top�� ����
		if(ArrMase[data->Row][data->Column]!='S' && ArrMase[data->Row][data->Column]!='D')//������ ������ ����
			ArrMase[data->Row][data->Column]='+';//���ÿ� ����� �� ǥ��
		pushStack(temp,(void*)data);
		popStack(stack);
	//	free(popStack(stack));//������ ������ ����
	}
	//destroyStack(stack);//��� ���� ����
	
/*	for(i=0;i<5;i++)//ã�� �� ���
	{
		for(j=0;j<5;j++)
			printf("%c",ArrMase[i][j]);
		printf("\n");
	}
	*/
}

STACK* Find :: Send()
{
	return this->temp;
}
void Find :: Check(int &x, int &y)
{
	if(!emptyStack(stack))//�� �������� Ȯ��
	{
		mData* data = (mData*)stackTop(stack);//chack�� top�� ����
	//	if(ArrMase[check->Row][check->Column]!='S' && ArrMase[check->Row][check->Column]!='D')//������ ������ ����
//			ArrMase[check->Row][check->Column]='+';//���ÿ� ����� �� ǥ��
		x = data->Row;
		y = data->Column;
		free(popStack(stack));//������ ������ ����
	}
}
mData* Find :: Dsend()
{
	return this->data;
}