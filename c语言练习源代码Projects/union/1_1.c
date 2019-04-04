#include<stdio.h>

struct infor
{
	int num;
	char name[10];
	char sex;
	char job;

		union postion
		{
		int banji;
		char position[10];
		}lei;
}person[2];

void main()
{

int i=0;
	while(i<2)
	{
	printf("input a num:");
	scanf("%d",&person[i].num);
	
	printf("input a name:");
	scanf("%s",&person[i].name);

    printf("input sex(m/f):");
	scanf("%s",&person[i].sex);

	printf("input job:");
	scanf("%s",&person[i].job);
	
	

	if(person[i].job =='s')
		{
		  printf("input banji:");
		  scanf("%d",&person[i].lei.banji);
		}
	else if(person[i].job =='t')
		{
		  printf("input postion:");
		  scanf("%s",&person[i].lei.position);
		}
	else
		{
		printf("Inputing Error!\n");
		}
	i++;
	putchar('\n');
	}
    putchar('\n\n');
    printf("num\tname\tsex\tjob\tclass/postion\t\n");
	
	    for(i=0;i<2;i++)
		{
			if(person[i].job =='s')	
			{
				printf("%d\t%s\t%c\t%c\t%d\t\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].lei.banji);
			}
			else 	
			{
				printf("%d\t%s\t%c\t%c\t%s\t\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].lei.position);
			}
		}


}