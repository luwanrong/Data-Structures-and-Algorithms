#include<stdio.h>
void main()
{
char c='k';
int i=1,j=2,k=3;
double x=3e+5,y=0.85;
printf("%d,%d\n",!x*!y,!!!x);//0, 0
printf("%d,%d\n",x||i&&j-3,i<j&&x<y);//1,0
printf("%d,%d\n",i==5&&c&&(j=8),x+y||i+j+k);//0,1



}