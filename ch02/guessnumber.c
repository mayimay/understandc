#include <stdio.h>
int main(void)
{
	int a[4]={1,2,3,4};
	int b[4];
	int n,m;
    char c[4];
	do
 {

    printf("请输入4个数字\n");
    scanf("%s",c);
    for (int i = 0; i < 4; ++i)
    {
        if(c[i] <= '9' && c[i]>='0')
        {
            b[i] = c[i] - '0';
        }   /* code */
    }


 	n=m=0;
    // for(int i=0;i<4;i++)
    // {
    // 	scanf("%s",&b[i]);
    // }
    for(int i=0;i<4;i++)
    {
    	for(int j=0;j<4;j++)
    	{
         if(a[i]==b[j])
         	m++;
    	}
    }
    printf("包含%d个正确的数字\n",m);
   for(int i=0;i<4;i++)
    {
    	if(a[i]==b[i])
    		n++;
    }
    printf("%d个数字位置正确\n",n);
 }
 while(n!=4);
 	return 0;
}