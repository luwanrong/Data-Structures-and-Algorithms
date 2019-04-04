#include<stdio.h>
void main()
{
int n=0;
printf("input a string:\n");
while(getchar()!='\n')//条件表达式：getchar()!='\n'表示当输入的字符不是回车时，就执行循环体。 
{
    n++;
}
printf("%d\n",n);

}    