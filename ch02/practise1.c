#include <stdio.h>
int main()
{
	int i,m;
	int layer;
	printf("请输入金字塔的层数");
	scanf("%d",&layer);
	for(i=0;i<layer;i++)
	{
		for(m=0;m<layer-i-1;m++)
		{
			printf(" ");
		}
        for(int n=0;n<2*i+1;n++)
        {
        	printf("*");
        }
        printf("\n");
	}
	return 0;
}