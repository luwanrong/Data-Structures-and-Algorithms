#include<stdio.h>
void main()
{
int year,b;
printf("������һ����ݣ�");
scanf("%d",&year);
b=year%4;
switch(b)
{ 
case 0:
	{
	
     if(year%100==0)
	 {
		 if(year%400==0)
		 {
		 printf("YES!\n");
		 }
		 else
		 {
		 printf("NO!\n");
		 }
	 }
	 else
	 {
	 printf("YES!");
	 
	 }
	 break;
	}
default:printf("NO!\n");
	}
 

}

