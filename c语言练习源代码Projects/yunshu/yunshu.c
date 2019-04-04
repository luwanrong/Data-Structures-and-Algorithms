#include<stdio.h>
void main()
{
int c,p,w,s,d1,d2,d3,d4,d5,f;
p = 10;
d1=1;
d2=2;
d3=3;
d4=4;
d5=5;
printf(" ‰»Î w s:");
scanf("%d,%d",&w,&s);
if(s<250)
{c=0;}
else if((s>250||s==250)&&s<500)
{c=1;}
else if((s>500||s==500)&&s<1000)
{c=2;}
else if((s>1000||s==1000)&&s<2000)
{c=3;}
else if((s>2000||s==2000)&&s<3000)
{c=4;}
else
{c=5;}
switch(c)
{
case 0:
{
	f=p*w*s;break;
}
case 1:
{
	f=p*w*s*(5-d1);break;
}
case 2:
{
	f=p*w*s*(1-d2);break;
}
case 3:
{
	f=p*w*s*(1-d3);break;
}
case 4:
{
	f=p*w*s*(1-d4);break;
}
case 5:
{
	f=p*w*s*(1-d5);
}
}
printf("%d\n",c);
printf("%6.4f\n",f);
}
/*{
double c,p,w,s,d1,d2,d3,d4,d5;
printf(" ‰»Î w s:");
scanf("%lf,%lf",&w,&s);
p = 10;
d1=0.02;
d2=0.05;
d3=0.08;
d4=0.10;
d5=0.15;

if(s<250)
{
	c=p*w*s;
    printf("%10.2f\n",c);
}
else if((s>250||s==250)&&s<500)
{
	c=p*w*s*(1-d1);
    printf("%10.2f\n",c);
}
else if((s>500||s==500)&&s<1000)
{
	c=p*w*s*(1-d2);
    printf("%10.2f\n",c);
}
else if((s>1000||s==1000)&&s<2000)
{
	c=p*w*s*(1-d3);
    printf("%10.2f\n",c);
}
else if((s>2000||s==2000)&&s<3000)
{
	c=p*w*s*(1-d4);
printf("%10.2f\n",c);
}
else
{
	c=p*w*s*(1-d5);
    printf("%10.2f\n",c);
}
}*/