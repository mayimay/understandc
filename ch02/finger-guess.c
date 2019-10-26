#include <stdio.h>
#define MAX-GAMER 5;
enum Flag{
	QUIT,CHOOSE,GUESSING,WIN;
}
enum Flag STATUS=CHOOSE;
enum gameStatus{
	READY,OUT,DRAW;
}
int 
int fingerResult[3][3]={{0,-1,1},{1,0,-1},{1,-1,0}}
int gameTatal;
int gameStatus[]={READY,READY,READY,READY,READY};
int gameFingers[]={0};
int main()
{

while(1)
{
 switch (STATUS)
 {
	printf("进入猜拳游戏\n", );
	fingerGuessing();
	case CHOOSE;break;
	//选择人数
	choosParticipant();
	STATUS=GUESSING;
	case WIN;
	//有一人胜出，进去选择继续还是退出
	case GUESSING;
	//进行猜拳结果展示
	printf("进入到猜拳,人数:%d,\n"particpantTotal);
	

  }
}
  return 0;
}
void fingerGuessing(){
	int totalLeft=0;
//如果就剩一个人，就是胜出
	for(int i=0;i<gameTatal;++i)
	{
		if(gameStatus[i]!=OUT){
			totalLeft++;
		}

	}
	if(totalLeft==1){
		STATUS=WIN;
		//TODO 打印获胜者
		return;
	}
	if (gameStatus[0]==READY)
	{
		printf("请输入（0.剪刀，1.石头，2.布）\n");
		gameFingers[0]==canInt;
	}
}
void choosParticipant()
{
	printf("请输入进行猜拳的人数：（2～5）\n");
	
	}
int canInt(int min,int max){
	int rlt,input;
	do{
		rlt=scanf("%d",&input);
		if(rlt==0){
			printf("输入不合法\n");
		}
		if(input<min||input>max){
			printf("输入范围不满足：（%d~%d）\n", );
		}
	}while(rlt==0);
	
}
void compete()
{
	int firetGamerIndex;
    for (int i = 0; i < gameTatal; ++i)
    {
    	if(gameStatus[i]==READY)
    	{
           firetGamerIndex=i;
    	break;
    	}
    	
    }
 int rlt=compareFinger(first:0,secend:2);
}
int compareFinger(int first,int secend)
[
	return fingerResult
	return 0;
]















