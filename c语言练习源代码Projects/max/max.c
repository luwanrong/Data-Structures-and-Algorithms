#include<stdio.h>
void main()
{
int a,b,max;
printf("\n input two num:");
scanf("%d%d",&a,&b);
max = a;
if(max<b)//Ҫ��Ϊ�٣��Ͳ�ִ�� 
{
  max=b;
}
printf("\n max=%d\n",max);

}