#include<stdio.h>
struct process
{
	int pid,at,st,ft,tt,wt,bt,rt;
	
};

void main()
{

struct process a[5];
struct process temp;
int i,j,att=0,awt=0,t,tet=0;
printf("\nEnter the quantum time:");
scanf("%d",&t);
for(i=0;i<5;i++)
{
	printf("\nEnter the  burst time  process %d : ",i);
	a[i].pid=i;
	a[i].at=0;
	scanf("%d",&a[i].bt);
	tet=tet+a[i].bt;
	a[i].rt=a[i].bt;
}
while(tet!=0)
{
	for(i=0;i<5;i++)
	{
		printf("\ntet=%d",tet);		
		if(a[i].rt>=t)
		{
			a[i].rt=a[i].rt-t;
			tet=tet-t;
			printf("\npid = %d | rt = %d | tet = %d \n",a[i].pid,a[i].rt,tet);
			
		}

		else if(a[i].rt>0 && a[i].rt<t)
		{
			
			tet=tet-a[i].rt;
			a[i].rt=0;
			printf("\n pid=%d | rt=%d | tet=%d \n",a[i].pid,a[i].rt,tet);
					
		}
		else
			continue;
	}

}



}

