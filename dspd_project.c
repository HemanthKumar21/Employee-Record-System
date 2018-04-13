#include<stdio.h>
#include<string.h>
#define NUM 20
#define SIZE 50
struct Employee_Record
{
	char employee_name[SIZE];
	char project_name[SIZE];
	int number_of_hrs;
	struct address
	{
		int h_no;
		char city[SIZE];
	}employee_address;
	char phone_number[11];
	int employee_salary;
};
enum status_code{FAILURE,SUCCESS};
void initialization(struct Employee_Record record[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		record[i].employee_name[0]='\0';
		record[i].project_name[0]='\0';
		record[i].number_of_hrs=0;
		record[i].employee_address.h_no=0;
		record[i].employee_address.city[0]='\0';
		record[i].phone_number[0]='\0';
		record[i].employee_salary=0;		
	}
}
void bubblesort_list(struct Employee_Record record[],int n)
{
	int i,j,flag=1,p,flag1=1,k;
	struct Employee_Record record1;
	for(i=0;i<n-1 && flag==1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(record[j].project_name,record[j+1].project_name)>0)
			{
				record1=record[j];
				record[j]=record[j+1];
				record[j+1]=record1;
				flag=1;	
			}		
		}	
	}
	i=0;
	while(i<n)
	{
		p=i;
		while(strcmp(record[i].project_name,record[i+1].project_name)==0)
		{
			i++;		
		}
		for(j=p;j<p+i;j++)
		{
			for(k=p;k<p+(i-j);k++)
			{
				if(strcmp(record[k].employee_name,record[k+1].employee_name)>0)
				{
					record1=record[k];
					record[k]=record[k+1];
					record[k+1]=record1;	
				}
						
			}	
		}
		i++;
	}
}
enum status_code insert(struct Employee_Record records[],int n,char name[],char projectname[],int no_of_hours,int employeesalary,char city[],int houseno,char phone_number[])
{
	enum status_code status=SUCCESS;
	int found=0;int i,j,free_index;
	i=0;
	while((i<n) && !found)
	{
		if(strcmp(records[i].employee_name,name)==0 && strcmp(records[i].project_name,projectname)==0)
		{
			found=1;
			records[i].employee_salary=employeesalary;
			records[i].number_of_hrs=no_of_hours;
			strcpy(records[i].phone_number,phone_number);
			strcpy(records[i].employee_address.city,city);
			records[i].employee_address.h_no=houseno;
		}
		else
		{
			i++;
		}
	}
	if(found==0)
	{
		free_index=-1;
		i=0;
		while((i<n) && (free_index==-1))
		{
			if(strlen(records[i].employee_name)==0 && strlen(records[i].project_name)==0)
			{
				free_index=i;
			}
			else
			{
				i++;
			}
		}
		if(free_index>-1)
		{
			strcpy(records[free_index].employee_name,name);
			strcpy(records[free_index].project_name,projectname);
			records[free_index].employee_salary=employeesalary;
			strcpy(records[free_index].employee_address.city,city);
			records[free_index].employee_address.h_no=houseno;
			records[free_index].number_of_hrs=no_of_hours;
			strcpy(records[free_index].phone_number,phone_number);
			for(j=0;j<free_index+1;j++)
			{
			printf("\n%-10s",records[j].employee_name);
			printf("%-10s",records[j].project_name);
			printf("%-4d",records[j].number_of_hrs);
			printf("%-7d",records[j].employee_salary);
			printf("\tAddress:");
			printf("%-4d",records[j].employee_address.h_no);
			printf("%-10s",records[j].employee_address.city);
			printf("%-12s",records[j].phone_number);
			}
		}
		else
		{
			status=FAILURE;
			printf("\nrecord is full");
		}
	}
	return status;
}
enum status_code delete(struct Employee_Record record[],int n,char employee_name[],char project_name[])
{
	enum status_code status=SUCCESS;
	int found=0,i,j;
	i=0;
	while(i<n && !found)
	{
		if(strcmp(record[i].employee_name,employee_name)==0 && strcmp(record[i].project_name,project_name)==0)
		{
			found=1;
		}	
		else
		{
			i++;		
		}
	}
	if(found==0)
	{
		status=FAILURE;
		printf("\nRecord does not Exist");	
	}
	else
	{
		record[i].employee_name[0]='\0';
		record[i].project_name[0]='\0';
		record[i].number_of_hrs=0;
		record[i].employee_address.h_no=0;
		record[i].employee_address.city[0]='\0';
		record[i].phone_number[0]='\0';
		record[i].employee_salary=0;
		for(j=i;j<getNumRecords(record,n)-1;j++)
		{
			record[j]=record[j+1];		
		}
		for(j=0;j<getNumRecords(record,n);j++)
			{
			printf("\n%-10s",record[j].employee_name);
			printf("%-10s",record[j].project_name);
			printf("%-4d",record[j].number_of_hrs);
			printf("%-7d",record[j].employee_salary);
			printf("\tAddress:");
			printf("%-4d",record[j].employee_address.h_no);
			printf("%-10s",record[j].employee_address.city);
			printf("%-12s",record[j].phone_number);
			}
	}
	return status;
}
int getNumRecords(struct Employee_Record record[],int n)
{
	int c=0,i;
	for(i=0;i<n;i++)
	{
		if(strlen(record[i].employee_name)!=0 && strlen(record[i].project_name)!=0)
		{
			c++;		
		}
	}
	return (c-1);
}
void isEmpty(struct Employee_Record record[],int n)
{
	int active_records;	
	active_records=getNumRecords(record,n);
	if(active_records==0)
	{
		printf("\nList is empty");	
	}
	else
	{
		printf("\nList is not empty");	
	}	
}
void isFull(struct Employee_Record record[],int n)
{
	int active_records;	
	active_records=getNumRecords(record,n);
	if(active_records==n)
	{
		printf("\nList is full");	
	}
	else
	{
		printf("\nList is not full");	
	}
}
void getMaxNumHrs(struct Employee_Record records[],int n,char projectname[])
{
   int highest_no_of_hours=0,i,j=0,c;
   for(i=0;i<n;i++)
   {
   		if(strcmp(records[i].project_name,projectname)==0)
	   	{
   			if(highest_no_of_hours<records[i].number_of_hrs)
   			{	
   		    	 	highest_no_of_hours=records[i].number_of_hrs;
			}
		}
   }
   printf("\nhighest no of hours is %d",highest_no_of_hours);
   c=getNumRecords(records,NUM);
   for(i=0;i<c;i++)
   {
    	if((records[i].number_of_hrs==highest_no_of_hours) && strcmp(records[i].project_name,projectname)==0)
   		{	
       		printf("\n%s",records[i].employee_name);
  		}	
	}
}
void findTopMostWorkingEmployee(struct Employee_Record records[],int n)
{
	int i=0,j,no_of_hours=0;int max=0;
	char xname[SIZE];int c;
	c=getNumRecords(records,NUM);
	while(i<c)
	{
		no_of_hours=0;
	    strcpy(xname,records[i].employee_name);
	    no_of_hours=records[i].number_of_hrs;
	    i++;
	    j=i;
	    while(j<c)
	    {
	     	if(strcmp(xname,records[j].employee_name)==0)
	     	{
	     		no_of_hours=no_of_hours+records[j].number_of_hrs;
			}	
		    j++;
		}
		if(no_of_hours>max)
		{
	 	  max=no_of_hours;
		}
	}
	printf("\ntop most working employeee works for %d",max);
	i=0;no_of_hours=0;
	while(i<c)
	{
		no_of_hours=0;
	    strcpy(xname,records[i].employee_name);
	    no_of_hours=records[i].number_of_hrs;
	    i++;
	    j=i;
	    while(j<c)
	    {
	     	if(strcmp(xname,records[j].employee_name)==0)
	     	{
	     		no_of_hours=no_of_hours+records[j].number_of_hrs;
			}
			j++;
		}
		if(no_of_hours==max)
		{
		 	 printf("\n%s",xname);
	    }
	}
}
void Find_Kth_TopmostProject(struct Employee_Record record[],int n,int k)
{
	int i,p=0,flag,j,temp,d,index[n],b[n],no_of_hrs;
	float average[n],c;
	for(i=0;i<getNumRecords(record,n);i++)
	{
		b[i]=1;
	}
	for(i=0;i<getNumRecords(record,n);i++) 
    	{  
 	   if(b[i]!=0)
	   { 
 	   	no_of_hrs=0;
		c=0;
       	        for(j=0;(j<n);j++)
     		{   
   	  		if(strcmp(record[i].project_name,record[j].project_name)==0)
   	   		{   
				index[p]=i;
	    		        no_of_hrs=no_of_hrs+record[j].number_of_hrs;
				b[j]=0;
				c++;
		  	}
	   	}
		average[p]=no_of_hrs/c;
	        p++;
	   }
	}
	flag=1;
    	for(i=0;((i<getNumRecords(record,n)-1)&&(flag==1));i++)
	{   
		flag=0;
		for(j=0;j<getNumRecords(record,n)-i-1;j++)
		{
			if(average[j]<average[j+1])
			{
				temp=average[j];
				average[j]=average[j+1];
				average[j+1]=temp;
				temp=index[j];
				index[j]=index[j+1];
				index[j+1]=temp;
				flag=1;
			}
		}
	}
	i=0;
	p=1;
	j=0;
	while(p<k)
	{   
		j=i+1;
		while(average[i]==average[j])
		{
			j++;
		}
		i=j;
		p++;
	}
	while(average[i]==average[j])
	{	
		d=index[j];
		printf("\n%s",record[d].project_name);
		j++;
	}
}
void Find_Least_PopularProjects(struct Employee_Record records[],int n,float k,int p)
{
	int i,j,b[n],d,c1[n],l=0;
	float c;
	int no_of_employee=0,no_of_hours;
        for(i=0;i<n;i++)
	{
		b[i]=1;
	}
	for(i=0;i<getNumRecords(records,n);i++) 
    	{  
           
 	   if(b[i]!=0)
	   { 
                no_of_employee++;
       	        for(j=0;(j<n);j++)
     		{   
   	  		if(strcmp(records[i].employee_name,records[j].employee_name)==0)
   	   		{
				b[j]=0;					
			}
		}
	   }
	}
        c=(k*no_of_employee)/100;
	 for(i=0;i<n;i++)
	{
		b[i]=1;
	}  
    	for(i=0;i<getNumRecords(records,n);i++)
   	{  
    		if(b[i]!=0)
   		{  
	     		no_of_employee=0;
	     		no_of_hours=0;
	     		for(j=0;j<getNumRecords(records,n);j++)
     			{   
   			   if(strcmp(records[i].project_name,records[j].project_name)==0)
   			   {   
			         b[j]=0;
                	         no_of_hours=no_of_hours+records[j].number_of_hrs;
				 no_of_employee++;
		         
			   }
	   		}
			if(no_of_hours<p && no_of_employee>=c)
			{
	   			c1[l]=i;
	   			l++;
	   		}
     		}
   	}
	if(l==0)
	{
		printf("\nthere are no such projects");	
	}
   	for(i=0;i<l;i++)
   	{
   		d=c1[i];
   		printf("\n%s",records[d].project_name);
   	}
}
void list_union(struct Employee_Record record1[],int n,struct Employee_Record record2[],int m,struct Employee_Record record3[],int p)
{
	int i,j,k,found;
	for(i=0;i<getNumRecords(record1,NUM);i++)
	{		
		record3[i]=record1[i];
	}
	for(j=0;j<getNumRecords(record2,NUM);j++)
	{
		found=0;
		for(k=0;k<getNumRecords(record1,NUM);k++)
		{
	if(strcmp(record2[j].employee_name,record1[k].employee_name)==0 && strcmp(record2[j].project_name,record1[k].project_name)==0) 		{
		found=1;
	}			
		}
		if(found==0)
		{
			record3[i]=record2[j];
			i++;
		}	
		
	}
	bubblesort_list(record3,i);
	for(j=0;j<i;j++)
	{
		printf("\n%-10s",record3[j].employee_name);
		printf("%-10s",record3[j].project_name);
		printf("%-4d",record3[j].number_of_hrs);
		printf("%-7d",record3[j].employee_salary);
		printf("\tAddress:");
		printf("%-4d",record3[j].employee_address.h_no);
		printf("%-10s",record3[j].employee_address.city);
		printf("%-12s",record3[j].phone_number);
	}
}
void list_intersection(struct Employee_Record record1[],int n,struct Employee_Record record2[],int m,struct Employee_Record record3[],int p)
{
	int i,j=0,k=0;
  	for(i=0;i<getNumRecords(record1,n);i++)
	{
		for(j=0;j<getNumRecords(record2,m);j++)
		{
			if(strcmp(record1[i].employee_name,record2[j].employee_name)==0 && strcmp(record1[i].project_name,record2[j].project_name)==0)
			{
				if(record1[i].employee_salary>record2[j].employee_salary)
				{
					record3[k]=record1[i];
					k++;			
				}
				else
				{
					record3[k]=record2[j];
					k++;				
				}
			} 		
		}
	}
	printf("%d",k);
	bubblesort_list(record3,k);
	for(j=0;j<k;j++)
	{
		printf("\n%-10s",record3[j].employee_name);
		printf("%-10s",record3[j].project_name);
		printf("%-4d",record3[j].number_of_hrs);
		printf("%-7d",record3[j].employee_salary);
		printf("\tAddress:");
		printf("%-4d",record3[j].employee_address.h_no);
		printf("%-10s",record3[j].employee_address.city);
		printf("%-12s",record3[j].phone_number);		
	}
}
void list_difference(struct Employee_Record record1[],int n,struct Employee_Record record2[],int m,struct Employee_Record record3[],int p)
{
	int i,j,k=0,found;
	for(i=0;i<getNumRecords(record1,n);i++)
	{
		found=0;
		for(j=0;j<getNumRecords(record2,m);j++)
		{
			if(strcmp(record1[i].employee_name,record2[j].employee_name)==0 && strcmp(record1[i].project_name,record2[j].project_name)==0)
			{
				found=1;
			}
		}
		if(found==0)
		{
			record3[k]=record1[i];
			k++;			
		}	
	}
	bubblesort_list(record3,k);
	for(j=0;j<k;j++)
	{
		printf("\n%-10s",record3[j].employee_name);
		printf("%-10s",record3[j].project_name);
		printf("%-4d",record3[j].number_of_hrs);
		printf("%-7d",record3[j].employee_salary);
		printf("\tAddress:");
		printf("%-4d",record3[j].employee_address.h_no);
		printf("%-10s",record3[j].employee_address.city);
		printf("%-12s",record3[j].phone_number);		
	}
}
main()
{
	struct Employee_Record record1[NUM],record2[NUM],record3[2*NUM];
	enum status_code status;
	FILE *fp1,*fp2;
	char name[SIZE],projectname[SIZE],city[SIZE],phoneno[11];
	int i,j,noofhrs,salary,houseno,active_records,k,p;
	float percent;
	initialization(record1,NUM);
	initialization(record2,NUM);
	fp1=fopen("record1.txt","r");
	for(i=0;!feof(fp1);i++)
	{
		fscanf(fp1,"%s",name);
		strcpy(record1[i].employee_name,name);
		fscanf(fp1,"%s",projectname);
		strcpy(record1[i].project_name,projectname);
		fscanf(fp1,"%d",&noofhrs);
		record1[i].number_of_hrs=noofhrs;
		fscanf(fp1,"%d",&salary);
		record1[i].employee_salary=salary;
		fscanf(fp1,"%d",&houseno);
		record1[i].employee_address.h_no=houseno;
		fscanf(fp1,"%s",city);
		strcpy(record1[i].employee_address.city,city);
		fscanf(fp1,"%s",phoneno);
		strcpy(record1[i].phone_number,phoneno);	
	}
	fp2=fopen("record2.txt","r");
	for(i=0;!feof(fp2);i++)
	{
		fscanf(fp2,"%s",name);
		strcpy(record2[i].employee_name,name);
		fscanf(fp2,"%s",projectname);
		strcpy(record2[i].project_name,projectname);
		fscanf(fp2,"%d",&noofhrs);
		record2[i].number_of_hrs=noofhrs;
		fscanf(fp2,"%d",&salary);
		record2[i].employee_salary=salary;
		fscanf(fp2,"%d",&houseno);
		record2[i].employee_address.h_no=houseno;
		fscanf(fp2,"%s",city);
		strcpy(record2[i].employee_address.city,city);
		fscanf(fp2,"%s",phoneno);
		strcpy(record2[i].phone_number,phoneno);	
	}
	j=1;
	while(j>0)
	{
		printf("\nenter your option");
		printf("\n1.INSERT");
		printf("\n2.DELETE");
		printf("\n3.GET NUMBER OF RECORDS");
		printf("\n4.TO CHECK LIST IS EMPTY");
		printf("\n5.TO CHECK LIST IS FULL");
		printf("\n6.GET MAXIMUM NUMBER OF HOURS");
		printf("\n7.FIND TOPMOST WORKING EMPLOYEE");
		printf("\n8.FIND KTH TOPMOST PROJECT");
		printf("\n9.FIND LEAST POPULAR PROJECT");
		printf("\n10.UNION OF TWO LISTS");
		printf("\n11.INTERSECTION OF TWO LISTS");
		printf("\n12.DIFFERENCE OF TWO LISTS");
		printf("\n0.EXIT");
		scanf("%d",&i);
		switch(i)
		{
			case 0:
			{
				j=-2;
				break;		
			}
			case 1:
			{	
				printf("\nenter employee name");
				scanf("%s",name);
				printf("\nenter project name");
				scanf("%s",projectname);
				printf("\nenter no of hrs");
				scanf("%d",&noofhrs);
				printf("\nenter employee salary");
				scanf("%d",&salary);
				printf("\nenter house no");
				scanf("%d",&houseno);
				printf("\nenter city");
				scanf("%s",city);
				printf("enter phone number");
				scanf("%s",phoneno);
				status=insert(record1,NUM,name,projectname,noofhrs,salary,city,houseno,phoneno);
				if(status==SUCCESS)
				{
					printf("\nSUCCESS");			
				}
				else
				{
					printf("\nFAILURE");
					printf("\nList is full");			
				}				
				break;
			}
			case 2:
			{
				printf("\nenter employee name");
				scanf("%s",name);
				printf("\nenter project name");
				scanf("%s",projectname);
				status=delete(record1,NUM,name,projectname);
				if(status==SUCCESS)
				{
					printf("\nSUCCESS");			
				}
				else
				{
					printf("\nFAILURE");
					printf("entry does not exist");			
				}
				break;
			}	
			case 3:
			{
				active_records=getNumRecords(record1,NUM);
				printf("%d",active_records);
				break;	
			}
			case 4:
			{
				isEmpty(record1,NUM);
				break;	
			}
			case 5:
			{
				isFull(record1,NUM);
				break;		
			}
			case 6:
			{
				printf("\nenter project name");
				scanf("%s",projectname);
				getMaxNumHrs(record1,NUM,projectname);
				break;		
			}
			case 7:
			{
				findTopMostWorkingEmployee(record1,NUM);
				break;					
			}
			case 8:
			{
				printf("enter k");
				scanf("%d",&k);	
				Find_Kth_TopmostProject(record1,NUM,k);
				break;	
			}
			case 9:
			{
				printf("\nenter percentage of employees");
				scanf("%f",&percent);	
				printf("enter p");
				scanf("%d",&p);	
				Find_Least_PopularProjects(record1,NUM,k,p);
				break;		
			}
			case 10:
			{
				list_union(record1,NUM,record2,NUM,record3,2*NUM);
				break;		
			}
			case 11:
			{
				list_intersection(record1,NUM,record2,NUM,record3,NUM);
				break;		
			}
			case 12:
			{
				list_difference(record1,NUM,record2,NUM,record3,NUM);
				break;		
			}
			default:
			{
				printf("INVALID OPTION");
				break;		
			}
		}
		j++;
	}
	fclose(fp1);
	fclose(fp2);
}
