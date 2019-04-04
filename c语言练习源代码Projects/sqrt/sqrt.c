#include<stdio.h>
#include<math.h>
int main()
{
double i;
int d;
printf("input i:");
scanf("%lf",&i);
if(i>0&&i<1000)
{
d=sqrt(i);
printf("%d\n",d);
}
else
{
printf("digatal is illeage,input i again:\n");
scanf("%lf",&i);
 d=sqrt(i);
 printf("%d\n",d);
}


}