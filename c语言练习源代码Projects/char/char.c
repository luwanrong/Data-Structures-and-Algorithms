#include<stdio.h>
void main()
{
int a;
printf("输入分数a=");
scanf("%d",&a);
if(a<60)
{
printf("E\n");
}
else if((a>60||a==60)&&a<70)//注意不能写为60<=a<70
{
	printf("D\n");

}
else if((a>70||a==70)&&a<80)
{
	printf("C\n");
}
else if((a>80||a==80)&&a<90)
{
	printf("b\n");
}
else
{
	printf("A\n");
}
}