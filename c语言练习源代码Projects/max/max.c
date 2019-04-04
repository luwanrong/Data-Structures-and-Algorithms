#include<stdio.h>
void main()
{
int a,b,max;
printf("\n input two num:");
scanf("%d%d",&a,&b);
max = a;
if(max<b)//要是为假，就不执行 
{
  max=b;
}
printf("\n max=%d\n",max);

}