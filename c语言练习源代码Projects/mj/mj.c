#include<stdio.h>
#include<math.h>
void main()
{
double a,b,c,s,area;
a=3.0;
b=4.0;
c=5.0;
s=1.0/2*(a+b+c);//此时s为实型，1/2为整型=0，故用1.0/2*（a+b+c）
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("a=%7.2f,b=%7.2f,c=%7.2f,s=%7.2f\n",a,b,c,s);
printf("area=%7.2f\n",area);
} 