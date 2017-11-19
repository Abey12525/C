#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct syt
{
	char lab1;
	char op;
	char lab2;
}syt[10];

struct symtb
{
	int a;
}


void main()
{
	char c[20],st[5];
	int tab=1,nt=0;
	struct syt 	
	FILE *f=fopen("ip.txt","r");
	
	while(!feof(f))
	{
		
    		// reads text until newline 
    		fscanf(f,"%s", c);
		if(strcmp(c,"start")==0)
			printf(" strcmp  %s \n",c );
			nt=1;
		if(nt == 1)
		{		
			strcpy(st,c);
			nt=0;
		}
		
		//printf("%s",c);
		/*if(c=='\t')
		{
			tab++;
		}
		if(tab%2==0)
		{
			o	
		}
		else
		{
			
		}
		if(tab==1)
		{
			if(c=='\t')
			{
				i=0;
				if(strcmp(st,'start'))
					printf('\n test \n');
				nt=1;
			}
		}
				
			
			while(i<5)
				st[i]=c;
		{
			printf("%c", c);
		}*/
	}
    	fclose(f);
}
    
