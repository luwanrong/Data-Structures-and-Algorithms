#include<stdio.h>
void main()
{
 char a,b;
 printf("input character a,b\n");
 scanf("%c,%c",&a,&b);//在此处输入时应注意空格也是字符，如"%c,%c"则输入为a,b;如"%c%c则输入为ab;如"%c %c则输入为a b.
 printf("a=%c,b=%c\n",a,b);



}