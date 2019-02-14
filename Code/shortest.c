#include <stdio.h>

#define MAX 6  // Number of nodes
#define INFINITE 998  //infinity

int allselected(int *selected)
{
  int i;
  for(i=0;i<MAX;i++)
    if(selected[i]==0)
      return 0;
  return 1;
}

void shortpath(int cost[][MAX],int *preced,int *distance)
{
  int selected[MAX]={0};
  int current=0,i,k,dc,smalldist,newdist;
  for(i=0;i<MAX;i++)
    distance[i]=INFINITE;
  selected[current]=1;
  distance[0]=0;
  current=0;
  while(!allselected(selected))
  {
    smalldist=INFINITE;
    dc=distance[current];
    for(i=0;i<MAX;i++)
    {
      if(selected[i]==0)
      {                                             
        newdist=dc+cost[current][i];
        if(newdist<distance[i])
        {
          distance[i]=newdist;
          preced[i]=current;
        }
        if(distance[i]<smalldist)
        {
          smalldist=distance[i];
          k=i;
        }
      }
    }
    current=k;
    selected[current]=1;
   }
}


