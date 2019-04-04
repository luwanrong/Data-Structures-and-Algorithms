#include<stdio.h>
void main()
{
 int a=15;
 float b=123.1234567;
 double c=12345678.1234567;
 char d='p';
 printf("a=%d,%5d,%o,%x\n",a,a,a,a);
 printf("b=%f,%1f,%5.1f,%e\n",b,b,b,b);
 printf("c=%1f,%f%8.41f",c,c,c);
 printf("d=%c,%8c\n",d,d);

}