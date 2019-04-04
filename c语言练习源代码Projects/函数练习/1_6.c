#include<stdio.h>
int main()
{
int max4(int a,int b,int c,int d);

int a,b,c,d,m;
printf("input value of a,b,and d:");
scanf("%d %d %d %d",&a,&b,&c,&d);
m=max4(a,b,c,d);

printf("max is %d\n",m);
return 0;
}

int max4(int a,int b,int c,int d)
{
int max2(int a,int b);

int m;

m=max2(a,b);
m=max2(c,m);
m=max2(m,d);

return m;
}

int max2(int a,int b)
{
int z;

z=a>b?a:b;

return z;
}
