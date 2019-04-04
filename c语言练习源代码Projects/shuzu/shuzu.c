#include<stdio.h>
int main()
/*{
int i;
int a[10]={0,1,2,3,4,5,6,7,8,9};
	for(i=0;i<10;i++)
		{
		a[i]=i;
		printf("%d ",a[i]);//正序输出
		}
	putchar('\n');
	for(i=9;i>=0;i--)
	{
	a[i]=i;
	printf("%d ",a[i]);//反序输出

	}
putchar('\n');
}
{
int i,max,a[10];
printf("输入一个数:\n");
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		max=a[0];
		if(a[i]>max)
		{
			max=a[i];
			
		}

	}

printf("max num:%d\n",max);
}
{
	int i,a[20]={1,1};
	
	//printf("%d\n%d\n",a[1],a[2]);
    for(i=2;i<20;i++)
	{
	a[i]=a[i-1]+a[i-2];
	
	//printf("%d\n",a[i]);
	}
	for(i=0;i<20;i++)
		{
		if(i%4==0)
			{
			putchar('\n');
			}
		printf("%8d",a[i]);
		}
	putchar('\n');
}
{
int i,k,max,a[10];
printf("输入10个数:\n");
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);
	}
    putchar('\n');
	for(k=0;k<9;k++)//这个循环控制多少趟
	{
		for(i=0;i<9-k;i++)//这个循环是每趟比较的次数少一次
		{
		  if(a[i]>a[i+1])
		  {
		  max=a[i];
		  a[i]=a[i+1];
		  a[i+1]=max;
		  }
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
		putchar('\n');
	}
}*/
{
int i,j,s,f,v[3];
int a[5][3]={{80,75,92},{61,65,71},{59,63,70},{85,87,90},{76,77,85}};
s=0;
for(j=0;j<3;j++)
	{
		for(i=0;i<5;i++)
			{
			s=s+a[i][j];
			}
	v[j]=s/5;
	printf("%d\n",v[j]);
	s=0;
	}

f=v[0]+v[1]+v[2];
printf("%d\n",f/3);
}