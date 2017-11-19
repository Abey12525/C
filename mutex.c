#include<stdio.h>

int mutex=1,empty=5,full=0,x=0,ch;

int signal(int s)
{
	s++;
	return s;

}

int wait(int w)
{
	w--;	
	return w;
}


void pro()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	mutex=signal(mutex);
	printf("\n %3d pro \n",x++);
}

void con()
{
	mutex=wait(mutex);
	empty=signal(empty);
	full=wait(full);
	mutex=signal(mutex);
	printf("\n %3d con \n",x--);
}

void main()
{
	

	while(1)
	{
		printf("\n1. produce 2.consume 3.exit\n");
		scanf("%d",&ch);	
		if(ch==1)
		{
			if(mutex == 1 && full<5)
			{	
				pro();
				printf("\ntest");
			}
			else
			{
				printf("\n full ");
			}
		}
		else if(ch==2)
		{
			if(mutex == 1 && empty<5)
			{
				con();
			}
			else
			{
				printf("\n empty");
			}
		}
		else if(ch==3)
		{
			break;
		}
		
		else
		{
			printf(" \n Enter a valid choice");
		}
	}


}
