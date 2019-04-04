#include<stdio.h>
void main()
{
int c,s;
double p,w,d,f;
printf("please input price weight discount:");
scanf("%lf,%lf,%d",&p,&w,&s);
if(s<250)  c=0;

else if(s>=250&&s<500) c=1;

else if(s>=500&&s<1000) c=2;

else if(s>=1000&&s<2000) c=3;

else if(s>=2000&&s<3000) c=4;  

else c=5;


switch(c)
{
case 0:d=0;break;
case 1:d=0.02;break;
case 2:d=0.05;break;
case 3:d=0.08;break;
case 4:d=0.10;break;
case 5:d=0.15;break;
}
f=p*w*s*(1-d);
printf("yunfei shi %10.4f\n ",f);

}