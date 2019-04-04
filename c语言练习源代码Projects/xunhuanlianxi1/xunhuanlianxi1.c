#include<stdio.h>
void main()
/*{
int i,j,k,n;
n=0;
for(i=1;i<5;i++)
	for(j=1;j<5;j++)
		if(i!=j)
		for(k=1;k<5;k++)
			if(k!=i&&k!=j)
			{
			printf("%d%d%d\n",i,j,k);
			n++;
			}
printf("%d\n",n);
}
{
int i,j,k,n;
n=0;
for(i=1;i<5;i++)
	for(j=1;j<5;j++)
		for(k=1;k<5;k++)
			{
			if(i!=j&&i!=k&&j!=k)
			{ 
				printf("%d%d%d\n",i,j,k);
			    n++;
			}
			}

		printf("%d\n",n);
}
{
	int i,k;
	for(i=100;i<=200;i++)//题目：输出100-200之间不能被3整除的整数
		{
			k=i%3;
			if(k!=0)
				{
				printf("%d\n",i);
				}
		}
}*/
{//求fibonacci数列前40位
	int f1,f2,i;
	f1=1;
	f2=1;
		printf("%d\n",f1);
		printf("%d\n",f2);
		for(i=1;i<=19;i++)
		{
		f1=f1+f2;
		f2=f1+f2;
		printf("%d\n",f1);
		printf("%d\n",f2);
		}

}