/*#include<stdio.h>
void main()
{
char a,b,c;
printf("please input character a,b,c\n");
scanf("%c %c %c",&a,&b,&c);
printf("%d,%d,%d\n%c,%c,%c\n",a,b,c,a-32,b-32,c-32);


}*/
#include<stdio.h>

//void change(int *pp1,int *pp2);

void main()
{
	int *p1,*p2;
	int a,b;
//	printf("输入a和b的值：");
	scanf("%d %d\n",&a,&b);
	printf("max=%d,min=%d\n",a,b);
	//p1=&a;//把a的地址传给p1指针 
//	p2=&b;
	 
	/*if(a<b)
	{
		change(p1,p2);	
	} */
//	printf("max=%d,min=%d\n",a,b);
}

/*void change(int *pp1,int *pp2)
{
	int *p;
	p=pp1;
	pp1=pp2;
	pp2=p; 
}*/