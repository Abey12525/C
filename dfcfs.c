#include<stdio.h>
#include<stdlib.h>
void print(int ar[],int lt)
{
	int i;
	printf("\n---------------------------\n");
	for(i=0;i<lt;i++)
	{
		printf("%3d",ar[i]);
	}
	printf("\n");
}
/*******************************/
void fcfs(int ip[],int ds[],int np)
{
	int avw,i,sum=0;
	printf("\n");
	for(i=0;i<np;i++)
	{
		ds[i]=abs(ip[i+1]-ip[i]);
		printf("seek time of %d: %d",i,ds[i]);
		printf("\n");
		sum=sum+ds[i];
	}
	avw=sum/np;
	printf("Average waiting time: %d\n",avw);
}
/******************************/
void scan(int ip[],int np,int chp)
{
    int dl,avw,temp,i,j,s,t,dmx,idx,sum=0,k=0;
	printf("\n");
	printf("Enter the max of disc:");
	scanf("%d",&dmx);
	for(i=0;i<np;i++)
	{
		for(j=0;j<np;j++)
		{
			if(ip[j]>ip[j+1])
			{
				temp=ip[j];
				ip[j]=ip[j+1];
				ip[j+1]=temp;
			}
		}
	}
	for(i=0;i<np;i++)
    {
        printf("%3d",ip[i]);
    }
	for(i=0;i<np;i++)
	{
		if(ip[i]==chp)
		{
			idx=i;
			break;
		}
	}
    printf(" \n %d ",ip[np-1]);
    for(i=idx;i<np-1;i++)
    {
        s=abs(ip[i]-ip[i+1]);
        printf("\nSeek time : %d",s);
        sum=sum+s;
    }
    s=abs(ip[np-1]-dmx);
    printf("\nSeek time : %d",s);
    sum=sum+s;
    s=dmx-ip[idx-1];
    printf("\nSeek time : %d",s);
    sum=sum+s;
    for(i=idx-1;i>0;i--)
    {
        s=abs(ip[i]-ip[i-1]);
        printf("\nSeek time : %d",s);
        sum=sum+s;
    }
    avw=sum/np;
    printf("\nAverage seek time  %d \n",avw);
}
/**********************************/
void cscan(int ip[],int np,int chp)
{
    int avw,temp,i,j,s,dmx,idx,sum=0;
	printf("\n");
	printf("Enter the max of disc:");
	scanf("%d",&dmx);
	for(i=0;i<np;i++)
	{
		for(j=0;j<np;j++)
		{
			if(ip[j]>ip[j+1])
			{
				temp=ip[j];
				ip[j]=ip[j+1];
				ip[j+1]=temp;
			}
		}
	}
	for(i=0;i<np;i++)
    {
        printf("%3d",ip[i]);
    }
	for(i=0;i<np;i++)
	{
		if(ip[i]==chp)
		{
			idx=i;
			break;
		}
	}
    for(i=idx;i<np-1;i++)
    {
        s=abs(ip[i]-ip[i+1]);
        printf("\nSeek time : %d",s);
        sum=sum+s;
    }
    s=abs(ip[np-1]-dmx);
    printf("\nSeek time : %d",s);
    sum=sum+s+dmx;
    printf("\nSeek time : %d",dmx);
    for(i=0;i<idx-1;i++)
    {
        s=abs(ip[i]-ip[i+1]);
        printf("\nSeek time : %d",s);
        sum=sum+s;
    }
    avw=sum/np;
    printf("\nAverage seek time  %d \n",avw);
}
void main()
{
	int np,i,chp,avw,op,sum=0;
	printf("Enter the current head position :");
	scanf("%d",&chp);
	printf("\nEnter the length of the que\n");
	scanf("%d",&np);
	int ip[np+1],ds[np];
	ip[0]=chp;
	for(i=1; i<=np;i++)
	{
		printf("Enter the que ele:\n");
		scanf("%d", &ip[i]);
	}
	print(ip,np);

	while(1)
	{
	    printf("\n 1.fcfs 2.scan 3.cscan 4.exit");
		scanf("%d",&op);
        switch (op)
        {
        case 1:
        {
            fcfs(ip,ds,np);
            break;
        }
        case 2:
        {
            scan(ip,np+1,chp);
            break;
        }
        case 3:
        {
            cscan(ip,np+1,chp);
            break;
        }
        case 4:
        {
            exit(0);
        }
        default :
        {

            printf("Enter a valied option \n");
        }
        }

	}

}
