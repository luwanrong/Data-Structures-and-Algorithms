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
      struct person man[NUM]; //����ṹ������   numΪ3��˼��������ṹ��������������Ԫ�أ�ÿ��Ԫ�ض���person�ṹ��  
      int i;
      
      for( i=0; i < NUM; i++)            
      {            
            printf("input name:\n");            
            gets(man[i].name); //��ȡ�ַ���           
            printf("input phone:\n");            
            gets(man[i].phone);            
      }
      
      printf("name\t\t\tphone\n\n");
      
      for( i=0; i < NUM; i++)
      {
            printf("%s\t\t\t%s\n",man[i].name,man[i].phone);
      }
}*/

struct person //���� ����Ϊperson�Ľṹ��
{
char name[15];
char phone[11];
};
void main()
{
	struct person man[3];//����ṹ������

	int i;
		for(i=0;i<3;i++)
			{
			printf("input a name:\n");
			gets(man[i].name);//���õ����ַ�����������ĵ�һ��Ԫ�� �Դ�����...
			printf("input a phone num:\n");
			gets(man[i].phone);
			}
	printf("\t address list \t\n");
    printf("name\t\t\tphone\t\n");

        for(i=0;i<3;i++)
		{
			printf("%s\t\t\t%s\t",man[i].name,man[i].phone);//�������ÿһ��Ԫ������dayin
			putchar('\n');
		}

}
 

