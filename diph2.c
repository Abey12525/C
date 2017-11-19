#include<stdio.h>

struct cho
{
	int avl;
}chop[5];


struct phil
{
	int philno;
	int state;
}phil[5];
void main()
{
	int i,statesum=0;
	for(i=0;i<5;i++)
	{
		phil[i].philno=i+1;
		chop[i].avl=1;
		phil[i].state=0;
	}
	printf("\n\n");
	while(statesum<5)
	{
		for(i=0;i<5;i++)
		{
			if(chop[i].avl==1 && chop[(i+1)%5].avl==1 && phil[i].state==0)
			{				
				phil[i].state=1;
				statesum++;
				chop[i].avl=0;
				chop[(i+1)%5].avl=0;
				printf("Currently eating %d \n",i);
			}
		}
		printf("\n");
		for(i=0;i<5;i++)
		{
			if(phil[i].state==0)
			{
				printf("%d thinking \n",i);
			}
		}
		printf("\n\n\n");
		for(i=0;i<5;i++)
		{
			chop[i].avl=1;
		}
	}
}	
	


