#include<stdio.h>
#include <stdbool.h>
void main()
{
	int i,j,flag,so,flag2=0,k=0,flagB,lp,temp;
	int ss[5];
	int al[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int mx[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int nd[5][3];
	int in[3]={10,5,7};
	int av[3]={3,2,2};
	int flagS[5];
	for(i=0;i<5;i++)
	{
		ss[i]=0;
		flagS[i]=0;
		for(j=0;j<3;j++)
		{
			nd[i][j]=mx[i][j]-al[i][j];
		}
	}
	while(1)
	{
		for(i=0;i<5;i++)
		{			
			
			for(j=0;j<3;j++)
			{
				if(nd[i][j] <= av[j] && flagS[i]==0)
				{
					if(j==2)
					{
						for(lp=0;lp<3;lp++)
						{
							av[lp]+=al[i][lp];
						}
						ss[k]=i;
						k++;
						flagS[i]=1;	
						break;
					}
				}
				else
				{break;}
			}

		}
		if(k==4)
		{break;}
		
	}
	printf("\n");
	printf("allocation        max         need\n");	
	for(i=0;i<5;i++)
	{	for(j=0;j<3;j++)
		{
			printf("%d ",al[i][j]);
		}
		printf("         ");
		for(j=0;j<3;j++)
		{
			printf("%d ",mx[i][j]);
		}
		printf("         ");
		for(j=0;j<3;j++)
		{
			printf("%d ",nd[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------\n");
	for(i=0;i<5;i++)
	{
		printf("|P%d  |",ss[i]);
	}
	printf("\n------------------------------\n");
	printf("\n");	
}
