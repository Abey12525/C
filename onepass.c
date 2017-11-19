#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct 
{
	int val;
	char op[10];
}optab[10];

void main()
{
	FILE *f1,*f2,*f3,*f4,*f5;
	int sa[10],opval[10],i=0,j=0,m=0,len=0,k=0,l=0,loc[10],syma[10],syma1[10];
	char opnd[10][10],la[10][10],mne[10][10],s1[10],opnd1[10][10],opnd2[10][10];
	f1=fopen("input2.txt","r");
	f2=fopen("optab2.txt","r");
	f3=fopen("symtab.txt","w+");
	f4=fopen("symtab1.txt","w+");
	printf("---optab---\n");
	for(j=0;j<3;j++)
	{
		fscanf(f2,"%s %d",optab[j].op,&optab[j].val);
		printf("%s\t%d\n",optab[j].op,optab[j].val);
	}
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s",la[i],mne[i],opnd[i]);
		if(strcmp(mne[i],"START")==0)
		{
			loc[i]=atoi(opnd[i]);
			printf("------input file------\n");
		}
		else if(strcmp(mne[i-1],"END")!=0)
		{
			printf("%s\t%s\t%s\n",la[i],mne[i],opnd[i]);
			for(j=0;j<4;j++)
			{
				if(strcmp(optab[j].op,mne[i])==0)
				{	
					fprintf(f3,"%s\t%d\t*\n",opnd[i],loc[i-1]+1);
					strcpy(opnd1[k],opnd[i]);
					syma[k]=loc[i-1]+1;
					k++;
					sa[m]=loc[i-1];
					opval[m]=optab[i].val;
					m++;
					break;
				}
			}
		if(strcmp(mne[i],"WORD")==0|strcmp(mne[i],"eqi")==0)
		{
			loc[i]=loc[i-1]+3;
			fprintf(f4,"%s\t%d\t\n",la[i],loc[i-1]);
			strcpy(opnd2[l],la[i]);
			syma1[l]=loc[i-1];
			l++;			
		}
		else if(strcmp(mne[i],"RESW")==0)
		{
			loc[i]=loc[i-1]+atoi(opnd[i])*3;
			fprintf(f4,"%s\t%d\n",la[i],loc[i-1]);
			strcpy(opnd2[l],la[i]);
			syma1[l]=loc[i-1];
			l++;
		}
		else if(strcmp(mne[i],"BYTE")==0)
		{
			loc[i]=loc[i-1]+strlen(opnd[i])-3;
			fprintf(f4,"%s\t%d\n",la[i],loc[i-1]);
			strcpy(opnd2[l],la[i]);
			syma1[l]=loc[i-1];
l++;
		}
		else
		{
			loc[i]=loc[i-1]+3;
		}
}
		++j;
		++i;
		
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	len=loc[i-3]-loc[0];
	printf("H^%s^%s^%d \n",la[0],opnd[0],len);
	for(i=0;i<m;i++)
	{
		printf("T^%d^03^%d0000\n",sa[i],opval[i]);
	}	
	for(i=0;i<m;i++)
	{
		for(k=0;k<l;k++)
		{
			if(strcmp(opnd1[i],opnd2[k])==0)
			{
				printf("M^%d^%d\n",syma[i],syma1[k]);
			}
		}
	}
	printf("E^%s\n",opnd[0]);
}	










