#include<stdio.h>
int main()
 {
 float average(float aver[],int n);

 float score1[]={86,85,90,92,89};
 float score2[]={90,80,79,86,90,95,95,86,88,70};
 float y1,y2;
 
 y1=average(score1,5);
 y2=average(score2,10);

 printf("the average score of chass1 is %5.2f\n",y1);
 printf("the average score of chass2 is %5.2f\n",y2);

 }

float average(float aver[],int n)
{
int i;
float sum,fin;
sum=aver[0];
for(i=1;i<n;i++)
{
	sum=sum+aver[i];

}

 fin=sum/n;
return fin;

}