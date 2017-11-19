#include<stdio.h>
struct pr
{
	int at,pid,bt,ft,tt,wt,st;
}s[10];

void main()
{
	struct pr temp;
	int i,j,k,l,m,np,tt,wt;
	tt=0;
	wt=0;
	printf("Enter the no of process:");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter Pid: arrival time: Burst:");
		scanf("%d%d%d",&s[i].pid,&s[i].at,&s[i].bt);
	}
	for(i=0;i<np;i++)
	{
		for(k=0;k<(np-i-1);k++)
		{
			if(s[k].at > s[k+1].at)
			{
				temp=s[k];
				s[k]=s[k+1];
				s[k+1]=temp;
			}	
		}
	}
	for(l=0;l<np;l++)
	{
		if(l==0)
		{
			s[l].st=s[l].at;
			s[l].ft=s[l].bt;
			s[l].tt=s[l].ft-s[l].at;
			s[l].wt=s[l].st-s[l].at;
		}
		else
		{
			if(s[l].at > s[l-1].ft)
			{
				s[l].st=s[l].at;
			}
			else
			{
				s[l].st=s[l-1].ft;
			}			
			s[l].ft=s[l].bt+s[l].st;
			s[l].tt=s[l].ft-s[l].at;
			s[l].wt=s[l].st-s[l].at;
		}
	}
	printf("\n\n");
	printf("pid   at   bt   ft   wt   tt\n");   
	for(i=0;i<np;i++)
	{
		printf("%1d    ,%1d    ,%1d   ,%1d   ,%1d    ,%1d  \n",s[i].pid,s[i].at,s[i].bt,s[i].ft,s[i].wt,s[i].tt);
		printf("\n");
	}
	for(i=0;i<np;i++)
	{
		tt=s[i].tt+tt;
		wt=s[i].wt+wt;		
	}
	tt=(tt/np);
	wt=(wt/np);
	printf("\nAvg turnaround time: %d \n Avg waiting time: %d \n",tt,wt);
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("-----");	
	}
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("|P%d |",i);	
	}
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("-----");	
	}
	printf("\n");
	for(i=0;i<np;i++)
	{
		//printf("%d   %d",s[i].st,s[i].ft);
		if(s[i].st!=s[i-1].ft)
		{
			printf("   %d",s[i].ft);
		}
		else
		{	
			printf("%d   %d",s[i].st,s[i].ft);
		}
	}
	printf("\n");


 
}
