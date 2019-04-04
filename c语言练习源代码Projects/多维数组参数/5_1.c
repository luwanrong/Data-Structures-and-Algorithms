#include<stdio.h>
int main()
{
	int max(int a[3][4]);
	
	int b[3][4]={{1,3,5,7},{2,4,16,8},{5,6,34,10}},fin;
	
	fin=max(b);
	
	printf("max=%d\n",fin);
}
int max(int a[3][4])
{
	int i,j,max1;
	
	max1=a[0][0];
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(max1<a[i][j])
			{
			   max1=a[i][j];
			}
		}
	}
	
	return max1;
}