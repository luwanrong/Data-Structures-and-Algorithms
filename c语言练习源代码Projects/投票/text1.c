#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 4
struct person
{
      char name[20];
      int count;
}candidate[NUM] = {
                  {"С����", 0},
                  {"�Ծ���", 0}, 
                  {"�ɵ���", 0},
                  {"Ī����", 0}
                };

char *winner();

void main()
{
      int i, j;
      char candidate_name[20];

      printf("��ӭ�������ù�����ѡͶƱϵͳ:() \n\n");
      printf("��ѡ����: С����, �Ծ���, �ɵ���, Ī����(·�˼�)\n\n");
      
      for( i=1; i <= 10; i++ )
      {
            printf("�� %2d λͶƱ, ��д��֧�ֵĺ�ѡ������: ", i);
            scanf("%s", candidate_name);
            for( j=0; j < NUM; j++ )
            {
                  if( 0 == strcmp(candidate_name, candidate[j].name) )
                  {
                        candidate[j].count++;
                  }
            }
      }
      printf("\n");

      for( i=0; i < 4; i++ )
      {
            printf("%s ͬѧ��Ʊ��Ϊ: %d\n", candidate[i].name, candidate[i].count );
      }
      printf("\n");
      printf("����ͶƱ���ʤ���ߵ�: %s", winner() );

      printf("\n");
      system("pause");
}

char *winner()
{
      int i =0 , winner = i;
      
      for( i=1; i < NUM; i++ )
      {
            if( candidate[winner].count < candidate[i].count )
            {
                  winner = i;
            }
      }
      
      return candidate[winner].name;
}
