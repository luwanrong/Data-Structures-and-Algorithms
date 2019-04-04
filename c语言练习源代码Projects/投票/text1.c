#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 4
struct person
{
      char name[20];
      int count;
}candidate[NUM] = {
                  {"小甲鱼", 0},
                  {"苍井空", 0}, 
                  {"松岛枫", 0},
                  {"莫丁丁", 0}
                };

char *winner();

void main()
{
      int i, j;
      char candidate_name[20];

      printf("欢迎进入良好公民评选投票系统:() \n\n");
      printf("候选人有: 小甲鱼, 苍井空, 松岛枫, 莫丁丁(路人甲)\n\n");
      
      for( i=1; i <= 10; i++ )
      {
            printf("第 %2d 位投票, 请写下支持的候选人名字: ", i);
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
            printf("%s 同学得票数为: %d\n", candidate[i].name, candidate[i].count );
      }
      printf("\n");
      printf("本次投票活动的胜利者的: %s", winner() );

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
