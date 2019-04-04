#include<stdio.h>

int main()
{
	long int digui(int n);
	long int n,y;
	printf("input a num:");
	scanf("%d",&n);
    y=digui(n);

	printf("%d!=%ld\n",n,y);
	
}

long int digui(int n)
{
	long int z;
	
	if(n<0)
	{
		printf("it is error!\n");
		
	}
	else if(n==0||n==1)
	{
		z=1;
	}
	else
	{
		z=n*digui(n-1);
	}

	return z;
}