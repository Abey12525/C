#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void main()
{
	FILE *f1,*f2,*f3,*f4;
    	int loc_count,op1,len,strt,opstart=30;
    	char lable[20],opc[20],oper[20],otp[20];
    	f1=fopen("ip.txt","r");
	f4=fopen("interm.txt","w");
	f2=fopen("optab2.txt","w");
    	f3=fopen("symtab2.txt","w");
    	fscanf(f1,"%s%s%d",lable,opc,&op1);
	if(strcmp(opc,"start")==0)
	{		
		loc_count=op1;
		strt=op1;
	}    	
	while(!feof(f1))
    	{
		fscanf(f1,"%s%s%s",lable,opc,oper);
		if(strcmp(lable,"-")!=0)
        	{
        		fprintf(f3,"\t%d\t%s\n",loc_count,lable);
       		}
		else
		{
			if(strcmp(opc,"end")==0)
			{
				printf(" ");
			}
			else
			{
				fprintf(f2,"%d\t%s\t%d\n",loc_count,opc,opstart);
			}
		}
		fprintf(f4,"%d\t%s\t%s\t%s\n",loc_count,lable,opc,oper);
		if(strcmp(opc,"resw")==0)
            	{
               		op1=atoi(oper);
                	loc_count=loc_count+(3*op1);
            	}
            	else if(strcmp(opc,"byte")==0)
            	{
               	
                	len=strlen(oper)-3;
                    	loc_count=loc_count+len;
            	}
            	else if(strcmp(oper,"resb")==0)
            	{
                	op1=atoi(oper);
                	loc_count=loc_count+op1;
            	}
		else
		{
			loc_count+=3;
		}
		opstart+=2;
		if(strcmp(opc,"end")==0)
	        {
			printf("program length=%d \n",loc_count-strt);                	
			break;
        	}	
	}
		
}
