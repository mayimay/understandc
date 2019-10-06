#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void creat(int number,int b[]);/*生成其他人的出拳情况*/
int main()
{
	srand((int)time(NULL));
	int number,a,i;
	int b[6];
	printf("请输入参加游戏的人数\n");
	scanf("%d",&number);
	/*生成其他人的出拳*/
	/*0.石头。  1.剪刀。  2.布。*/
    creat(number,b);
    //printf("一共有%d个人参加游戏\n",number );
    printf("请选择你的\n");
    printf("0.石头。  1.剪刀。  2.布。\n");
    scanf("%d",&b[number-1]);
    for(i=0;i<number;i++)   
    {
    	printf("%d ",b[i] );
    }
	return 0;
} 
void creat(int number,int b[])
{
	int i,a;
    for (i = 0; i < number-1; i++)
    {
       a=rand();
       b[i]=a%3;
    }
}