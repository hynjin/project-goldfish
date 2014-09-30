#include "13011061.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Find :: Findmase()
{
    int PossibleMove=0;
    int cRow,cColumn,cBranch;
    int i,j;//for문에 사용
	int x,y;//배열 확인에 사용
	int ss,dd;//시작점,도착점 확인에 사용
	char ArrMase[6][6]; // dat 파일을 읽어서 mase를 저장하기 위한 배열
    FILE *fp;
    STACK* stack;
	mData* infor;//가지,행,열 저장 = dataPtr
	mData* check;//데이터 확인
    stack=createStack();
	temp=createStack();
    cRow=cColumn=i=j=x=y=ss=dd=0;
    
    if((fp=fopen("mase.txt", "r")) == NULL)//파일 열기
	{
       // puts("file open error: Cannot find mase.txt");
        exit(0);
    }
	
	for(i=0;i<5;i++)//파일안의 값을 읽어 배열에 저장
	{
			fscanf(fp,"%s",&ArrMase[i]);
	}
	fclose(fp);

	for(i=0;i<5;i++)//source 찾기
	{
		for(j=0;j<5;j++)
		{
			if(ArrMase[i][j]=='S')//시작점 찾음
			{
				cRow=i;//시작 좌표저장
				cColumn=j;
				ss=1;//시작점을 찾았음을 표시
			}
			if(ArrMase[i][j]=='D')//도착점 찾음
				dd=1;
		}
	}
	if(ss!=1 || dd!=1)//시작점을 찾지 못한경우
	{
		//printf("시작점 혹은 도착점을 찾을 수 없습니다.\n");
		exit(1);
	}
	
	while(ArrMase[cRow][cColumn]!='D')//현재 위치가 도착점이 아닐경우
	{
		x=cRow;//현재 위치를 비교할 값에 넣음
		y=cColumn;
		PossibleMove = 0;
		if((ArrMase[x+1][y]=='0' || ArrMase[x+1][y]=='D') && cRow!=4)//아래측 이동 가능한 길 확인
		{
			cRow=x+1;
			cColumn=y;
			PossibleMove++;
		}	
		if((ArrMase[x-1][y]=='0' || ArrMase[x-1][y]=='D') && cRow != 0)//위측
		{
			cRow=x-1;
			cColumn=y;
			PossibleMove++;
		}
		if((ArrMase[x][y-1]=='0' || ArrMase[x][y-1]=='D') && cColumn != 0)//좌측
		{
			cRow=x;
			cColumn=y-1;
			PossibleMove++;
		}
		if((ArrMase[x][y+1]=='0' || ArrMase[x][y+1]=='D') && cColumn != 4)//우측
		{
			cRow=x;
			cColumn=y+1;
			PossibleMove++;
		}
		if(PossibleMove !=0)//이동가능할 경우
		{
			cBranch=PossibleMove-1;//push할 길 제외하고 branch에 저장
			if(ArrMase[cRow][cColumn]!='D')//현재 위치가 도착점이 아닐경우
				ArrMase[cRow][cColumn]='X';//들렸던 길임을 표시
			if(!fullStack(stack))//꽉 찬 스택인지 확인
			{
				infor = (mData*)malloc(sizeof(mData));
				infor->Branch=cBranch;
				infor->Row=x;
				infor->Column=y;
				pushStack(stack,(void*)infor);//스택 추가
			}
		}
		else//이동 불가능할 경우
		{
			check = (mData*)stackTop(stack);//Top의 정보를 불러옴
			cRow = check->Row;
			cColumn = check->Column;
			cBranch = check->Branch;
			while(cBranch == 0)//길이 있을때까지 pop
			{
				if(!emptyStack(stack))//빈 스택인지 확인
				{
					check = (mData*)popStack(stack);//스텍 삭제
					cRow = check->Row;
					cColumn = check->Column;
					cBranch = check->Branch;
					free(check);//dataPtr 삭제
				}
				else//스택이 없을 경우 종료
				{
				//	printf("길을 찾을 수 없습니다.\n");
					exit(0);
				}
			}
		}
	}	
		
	//도착한 이후
	while(!emptyStack(stack))//빈 스택인지 확인
	{
		data = (mData*)stackTop(stack);//chack에 top을 저장
		if(ArrMase[data->Row][data->Column]!='S' && ArrMase[data->Row][data->Column]!='D')//시작점 도착점 제외
			ArrMase[data->Row][data->Column]='+';//스택에 저장된 길 표시
		pushStack(temp,(void*)data);
		popStack(stack);
	//	free(popStack(stack));//스택의 데이터 삭제
	}
	//destroyStack(stack);//모든 스택 삭제
	
/*	for(i=0;i<5;i++)//찾은 길 출력
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
	if(!emptyStack(stack))//빈 스택인지 확인
	{
		mData* data = (mData*)stackTop(stack);//chack에 top을 저장
	//	if(ArrMase[check->Row][check->Column]!='S' && ArrMase[check->Row][check->Column]!='D')//시작점 도착점 제외
//			ArrMase[check->Row][check->Column]='+';//스택에 저장된 길 표시
		x = data->Row;
		y = data->Column;
		free(popStack(stack));//스택의 데이터 삭제
	}
}
mData* Find :: Dsend()
{
	return this->data;
}