#include<stdio.h>
#include<stdlib.h>


void main()
{
	FILE *f_pic,*f_file,*f_finish;
	char pic_name[20],file_name[20],finish_name[20],ch;
	
	printf("请输入图片的名字：");
	scanf("%s",&pic_name);
	printf("请输入文件的名字：");
	scanf("%s",&file_name);
	printf("合成的新文件名字：");
	scanf("%s",&finish_name);
	
	if(!(f_pic=fopen(pic_name,"rb")))//二进制读，如果正确打开，则返回1反之为null
	{
		printf("不能正确打开图片%s\n",pic_name);
		return;
	}
	
	if(!(f_file=fopen(file_name,"rb")))//二进制读，如果正确打开，则返回1反之为null
	{
		printf("不能正确打开文件%s\n",file_name);
		return;
	}
	if(!(f_finish=fopen(finish_name,"wb")))//二进制xie，如果正确打开，则返回1反之为null
	{
		printf("不能正确打开文件%s\n",finish_name);
		return;
	}
	
				while(!(feof(f_pic)))//feof(f_pic)判断是不是f_pic的结尾，如果是返回1,返回0，说明不是文件的结尾
				{
					ch=fgetc(f_pic);
					fputc(ch,f_finish);
				}
				
				fclose(f_pic);
				while(!(feof(f_file)))  //feof(f_file)判断是不是f_file的结尾，如果是返回1，不是为0
				{
					ch=fgetc(f_file);
					fputc(ch,f_finish);
				}
				fclose(f_file);
				fclose(f_finish);
				printf("成功执行!\n");
		
		system("pause");
}
