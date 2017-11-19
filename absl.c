#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct check
{
	char lnelm[1000];
};
FILE *f1,*f2;
char add[150],test[100],len[10];
void main()
{
	struct check line;
	int init,i,j,p=0,loop,ttl,flag,intadd;
	f1=fopen("absip.txt","r");
	f2=fopen("absop.txt","w");
	printf("\nProcess init\n")
	while(!feof(f1))
	{
		fscanf(f1,"%s",line.lnelm);
		flag=0;
		i=12;
		if(line.lnelm[0]=='T')
		{
			if(flag==0)
			{
				for(init=2,p=0;line.lnelm[init]!='^';init++,p++)
				{
					add[p]=line.lnelm[init];
				}
			}
			intadd=atoi(add);
			flag=1;
			len[0]=line.lnelm[9];
			len[1]=line.lnelm[10];
			ttl=atoi(len)/3;
			for(loop=0;loop<ttl;loop++)
			{
				for(i,p=0;line.lnelm[i]!='^';i++,p++)
				{
					test[p]=line.lnelm[i];
				}
				fprintf(f2,"%d\t%s\n",intadd,test);
				intadd+=3;
				i++;
			}

		}
	}
}
