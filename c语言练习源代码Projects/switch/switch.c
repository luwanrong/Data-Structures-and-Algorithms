#include<stdio.h>
void main()
{
double a,b;
char c;
printf("input three epressions a (+,-,*,/) b:");
scanf("%lf%c%lf",&a,&c,&b);
switch(c)
{
case '+':{
	
	printf("%6.2lf\n",a+b);
	break;
		 
		 }
case '-':{
    printf("%6.2lf\n",a-b);
	break;

		 }
case '*':{
		 printf("%6.2lf\n",a*b);
	break;
		 
		 }
case '/':{
	printf("%6.2lf\n",a/b);
	break;
		 
		 }
default:printf("error");
	

}

}