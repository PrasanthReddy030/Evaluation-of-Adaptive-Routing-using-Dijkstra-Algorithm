#include"shortest.c"
#include <stdio.h>
#define MAX 6  // Number of nodes
#define INFINITE 998  //infinity

void printL(int L[][MAX])
{	int sum=0;

    for(int i=0;i<MAX;i++)
    {
     for(int j=0;j<i;j++)
     {
      if(L[i][j]>0)
      sum+=L[i][j];
     }
    }
    printf("\nNumber of transmission on links 3-2 and 5-4 are %d, %d respectively\n\n",L[2][1],L[4][3]);
    printf("\nTotal number of transmissions in all the links is: %d\n",sum);
}

void reset(int preced[MAX],int distance[MAX],int L[][MAX])
{
	 for(int i=0;i<MAX;i++)
	 {
	  for(int j=0;j<MAX;j++)
	  	L[i][j]=0;
	 }
 
	 for(int i=0;i<MAX;i++)
	 {
	 	preced[i]=0;
	 	distance[i]=0;
	 }
}

int main()
{
 int cost[MAX][MAX]=  
     {{INFINITE,2,INFINITE,1,INFINITE,INFINITE}, 
      {2,INFINITE,3,2,INFINITE,INFINITE}, 
      {INFINITE,3,INFINITE,INFINITE,1,5},
      {1,2,INFINITE,INFINITE,9,INFINITE},
      {INFINITE,INFINITE,1,9,INFINITE,2},
      {INFINITE,INFINITE,5,INFINITE,2,INFINITE}};

  int i,preced[MAX],distance[MAX],L[MAX][MAX], W[MAX][MAX],count=1,j,temp;
  float p=0.6;

   for(int i=0; i<MAX; i++)
    for(int j=0; j<MAX; j++)
     W[i][j]=cost[i][j];
 
 while(count<=15)
 {
	reset(preced,distance,L);
	printf("\n\n**************************Iteration NUmber=%d**************************\n\n",count);
	printf("\nCosts on links 3-2 and 5-4 are %d, %d respectively\n\n",cost[2][1],cost[4][3]);
   shortpath(cost,preced,distance);

  for(i=1;i<MAX;i++)
  {	j=i;
  	while(j!=0)
  	{
  		temp=preced[j];
   		L[j][temp]+=1;
  		L[temp][j]+=1;
  		j=temp;
  	}
  }
  	printL(L);

 	for(int i=0;i<MAX;i++)
  	{
  	 for(int j=0;j<MAX;j++)
  	 { 
  	 	if(W[i][j]!=INFINITE)
		cost[i][j]=(1-p)*cost[i][j]+p*(W[i][j]+5*L[i][j]);	
	   else
		cost[i][j]==INFINITE;
	 }
	}
	count++;
}
 return 0;
}