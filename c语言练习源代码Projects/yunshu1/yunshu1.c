#include<stdio.h>
void main()
{
double p,w,s,d,z;
p=100;
printf("w,s:\n");
scanf("%lf%lf",&w,&s);
if(s<250)                   d=0;
else if((s>=250)&&s<500)    d=0.02;
else if((s>=500)&&s<1000)   d=0.05;
else if((s>=1000)&&s<2000)  d=0.08;
else if((s>=2000)&&s<3000)  d=0.10;
else                        d=0.15;

z=p*w*s*(1-d);

printf("yunfeiwei=%15.2f\n",z);

}