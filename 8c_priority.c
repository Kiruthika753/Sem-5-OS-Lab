#include<stdio.h>
void main()
{
  int nop, t, wt[10], twt, tat[10], ttat, i, j, p[10], b[10], tmp;
  float awt, atat;
  awt=0.0;
  atat=0.0;
  printf("Enter the number of processes: ");
  scanf("%d", &nop);
  for(i=0;i<nop;i++)
  {
  printf("Enter the burst time for each Process %d: ", i);
  scanf("%d", &b[i]);
  }
  for(i=0;i<nop;i++)
  {
  printf("Enter the priority number of each Process %d: ", i);
  scanf("%d", &p[i]);
  }
  for(i=0;i<nop;i++)
  {
    for(j=0;j<nop;j++)
    {
      if(p[i]<p[j])
      {
        t=p[i];
        p[i]=p[j];
        p[j]=t;
        tmp=b[i];
        b[i]=b[j];
        b[j]=tmp;
      }
    }
  }
  wt[0]=0;
  tat[0]=b[0];
  twt=wt[0];
  ttat=tat[0];
  for(i=1;i<nop;i++)
  {
    wt[i]=wt[i-1]+b[i-1];
    tat[i]=wt[i]+b[i];
    twt+=wt[i];
    ttat+=tat[i];
  }
  awt=(float)twt/nop;
  atat=(float)ttat/nop;
  printf("Process No\tPriority No\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for(i=0;i<nop;i++)
  printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], b[i], wt[i], tat[i]);
  
  printf("Total Waiting Time: %d\n", twt);
  printf("Total Turn Around Time: %d\n", ttat);
  printf("Average Waiting Time: %f\n", awt);
  printf("Average Turn Around Time: %f\n", atat);
}
