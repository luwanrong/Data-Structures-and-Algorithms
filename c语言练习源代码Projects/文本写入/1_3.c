#include<stdio.h>

#define S 2

struct student
{
	char name[20];
	int num;
	int age;
	char addre[15];
}stu[S];
void main()
{
	FILE *fp;
	int i;
	if(!(fp = fopen("text.txt","r")))
	{
		printf("cannot open the file!\n");
		return;
	}
	
	/*printf("plesse input student's infornation:\n");
	
	for(i=0;i<S;i++)
	{
		scanf("%s %d %d %s",&stu[i].name,&stu[i].num,&stu[i].age,&stu[i].addre);
	}
	for(i=0;i<S;i++)
	{
		if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
		{
		printf("file write error!\n");
		fclose(fp);
		}
	}
	fclose(fp);*/
	for(i=0;i<S;i++)
	{
		if(fread(&stu[i],sizeof(struct student),1,fp)!=1)
		{
		printf("file read error!\n");
		fclose(fp);
		}
	}
	
		for(i=0;i<S;i++)
	{
		printf("%s %d %d %s\n",&stu[i].name,&stu[i].num,&stu[i].age,&stu[i].addre);
	}
		fclose(fp);
}