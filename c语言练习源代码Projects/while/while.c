#include<stdio.h>
void main()
{
int n=0;
printf("input a string:\n");
while(getchar()!='\n')//�������ʽ��getchar()!='\n'��ʾ��������ַ����ǻس�ʱ����ִ��ѭ���塣 
{
    n++;
}
printf("%d\n",n);

}    