#include<stdio.h>
#include<stdlib.h>


void main()
{
	FILE *f_pic,*f_file,*f_finish;
	char pic_name[20],file_name[20],finish_name[20],ch;
	
	printf("������ͼƬ�����֣�");
	scanf("%s",&pic_name);
	printf("�������ļ������֣�");
	scanf("%s",&file_name);
	printf("�ϳɵ����ļ����֣�");
	scanf("%s",&finish_name);
	
	if(!(f_pic=fopen(pic_name,"rb")))//�����ƶ��������ȷ�򿪣��򷵻�1��֮Ϊnull
	{
		printf("������ȷ��ͼƬ%s\n",pic_name);
		return;
	}
	
	if(!(f_file=fopen(file_name,"rb")))//�����ƶ��������ȷ�򿪣��򷵻�1��֮Ϊnull
	{
		printf("������ȷ���ļ�%s\n",file_name);
		return;
	}
	if(!(f_finish=fopen(finish_name,"wb")))//������xie�������ȷ�򿪣��򷵻�1��֮Ϊnull
	{
		printf("������ȷ���ļ�%s\n",finish_name);
		return;
	}
	
				while(!(feof(f_pic)))//feof(f_pic)�ж��ǲ���f_pic�Ľ�β������Ƿ���1,����0��˵�������ļ��Ľ�β
				{
					ch=fgetc(f_pic);
					fputc(ch,f_finish);
				}
				
				fclose(f_pic);
				while(!(feof(f_file)))  //feof(f_file)�ж��ǲ���f_file�Ľ�β������Ƿ���1������Ϊ0
				{
					ch=fgetc(f_file);
					fputc(ch,f_finish);
				}
				fclose(f_file);
				fclose(f_finish);
				printf("�ɹ�ִ��!\n");
		
		system("pause");
}
