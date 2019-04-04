#include<stdio.h>
/*void main()
{
	int i,k,y;
	int pingfang(int y);
	
	for(i=1;i<6;i++)
	{
		k=pingfang(i);
	    printf("%d\n",k);
	}
}
int pingfang(int x)
{


return (x*x);
}

#define PF(y) ((y)*(y))
void main()
{
int i,k;
for(i=1;i<6;i++)
{
//k=PF(i);
printf("%d\n",PF(i));
}

}


#define NUM 3

struct person
{      
      char name[20];      
      char phone[10];      
};

void main()
{      
      struct person man[NUM]; //定义结构体数组   num为3意思是在这个结构体数组中有三个元素，每个元素都是person结构体  
      int i;
      
      for( i=0; i < NUM; i++)            
      {            
            printf("input name:\n");            
            gets(man[i].name); //获取字符串           
            printf("input phone:\n");            
            gets(man[i].phone);            
      }
      
      printf("name\t\t\tphone\n\n");
      
      for( i=0; i < NUM; i++)
      {
            printf("%s\t\t\t%s\n",man[i].name,man[i].phone);
      }
}*/

struct person //定义 名称为person的结构体
{
char name[15];
char phone[11];
};
void main()
{
	struct person man[3];//定义结构体数组

	int i;
		for(i=0;i<3;i++)
			{
			printf("input a name:\n");
			gets(man[i].name);//将得到的字符串放入数组的第一个元素 以此类推...
			printf("input a phone num:\n");
			gets(man[i].phone);
			}
	printf("\t address list \t\n");
    printf("name\t\t\tphone\t\n");

        for(i=0;i<3;i++)
		{
			printf("%s\t\t\t%s\t",man[i].name,man[i].phone);//将数组的每一个元素依次dayin
			putchar('\n');
		}

}
 

