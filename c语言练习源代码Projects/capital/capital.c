#include<stdio.h>
void main()
{

char ch;

printf("input a character:");
scanf("%c",&ch);
 
if((65<ch||65==ch)&&(91>ch||91==ch))
{
ch=ch+32;
}
if((97<ch||97==ch)&&(122>ch||122==ch))
printf("%c\n",ch);

//ch=(ch>=65&&ch<=91)?(ch+32):ch;
//printf("%c\n",ch);  
}