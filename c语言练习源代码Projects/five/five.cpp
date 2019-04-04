#include<stdio.h>
void main()
{
int num,a,b,c,d,e,l;
printf("请输入一个正整数num (0---9999）:");
scanf("%d",&num);
if(num>9999) l=5;
else if(num>999) l=4;
else if(num>99) l=3;
else if(num>9) l=2;
else l=1;
printf("num shi %d weishu\n",l);
a=(int)(num/10000);
b=(int)((num-a*10000)/1000);
c=(int)((num-a*10000-b*1000)/100);
d=(int)((num-a*10000-b*1000-c*100)/10);
e=(int)(num-a*10000-b*1000-c*100-d*10);
printf("每一位数字为%d,%d,%d,%d,%d\n",a,b,c,d,e);
switch(l)
{
case 5:
	{
	printf("反序:%d%d%d%d%d\n",e,d,c,b,a);break;
	}
case 4:
	{
	printf("反序:%d%d%d%d\n",e,d,c,b);break;
	}
case 3:
	{
	printf("反序:%d%d%d\n",e,d,c);break;
	}
case 2:
	{
	printf("反序:%d%d\n",e,d);break;
	}
case 1:
	{
	printf("反序:%d\n",e);break;
	}
}








}