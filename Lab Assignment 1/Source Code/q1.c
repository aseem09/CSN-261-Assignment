#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int temp=0;
int usersAdded=0;
int initRollNo=101;
int unusedRollNo[1000];

struct node {
    int rollNo;
    char name[100];
    char dob[50];
    char address[200];
    long long int phone;
    struct node *prev;
    struct node *next;
};
	   
struct node *head = NULL;

void insert(int rollNo, char name[], char dob[], char address[], long long int phone){

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
    temp->rollNo = rollNo;
    strcpy(temp->name, name);
    strcpy(temp->dob, dob);
    strcpy(temp->address, address);
    temp->phone = phone;
    
   //if the list is empty
   if(head == NULL){
		temp->prev= temp;
		temp->next= temp;
		head= temp;
   		return;
   }
   else{
   		struct node* last = head->prev;
   		head->prev= temp;
   		last->next= temp;
   		temp->next= head;
   		temp->prev= last;
   }
   
   
}

void print() {

    struct node* temp = head;  
    int variable = 1;
    while(temp != head || variable) {
        variable = 0;
        printf("\n");
        printf("%d\n", temp->rollNo);
        printf("%s\n", temp->name);
        printf("%s\n", temp->dob);
        printf("%s\n", temp->address);
        printf("%lld\n\n", temp->phone);
        temp = temp->next;
    }
}
struct node* search( int searchRollNo) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    
    int variable = 1;			

    while(temp != head || variable) {
        variable = 0;
        int rollNo = temp->rollNo;
        if(rollNo == searchRollNo){
        	return temp;
        }
        temp = temp->next; 
    }
    return NULL;
}
void sort(){

	struct node *a = (struct node*)malloc(sizeof(struct node));
    struct node *b = (struct node*)malloc(sizeof(struct node));
    
    a= head;
    int rollNoA;
    int rollNoB;
    int var1 =1;
    int var2 =1;
    while(a != head || var1){
    	b= a->next;
    	rollNoA= a->rollNo;
    	var1=0;
    	while(b != head || var2){
    		rollNoB= b->rollNo;
    		var2=0;
    		if(rollNoA > rollNoB>0){
    		
    			int rollNo;
    			int phone;
    			char name[100],dob[50],address[200];
    			strcpy(name,a->name);
    			strcpy(dob,a->dob);
    			strcpy(address,a->address);
    			rollNo= a->rollNo;
    			phone= a->phone;
    			
    			
    			a->rollNo=b->rollNo;
    			strcpy(a->name,b->name);
    			strcpy(a->dob,b->dob);
    			strcpy(a->address,b->address);
    			a->phone=b->phone;
    			
    			b->rollNo=rollNo;
    			strcpy(b->name,name);
    			strcpy(b->dob,dob);
    			strcpy(b->address,address);
    			b->phone=phone;
    			
    					   		
    		}
    		b= b->next;	
    	}
    	a= a->next;
    }
}
void sortName(){

	struct node *a = (struct node*)malloc(sizeof(struct node));
    struct node *b = (struct node*)malloc(sizeof(struct node));
    
    a= head;
    int rollNoA;
    int rollNoB;
    int var1 =1;
    int var2 =1;
    while(a != head || var1){
    	b= a->next;
    	rollNoA= a->rollNo;
    	var1=0;
    	while(b != head || var2){
    		rollNoB= b->rollNo;
    		var2=0;
    		if(strcmp(a->name,b->name)>0){
    		
    			int rollNo;
    			int phone;
    			char name[100],dob[50],address[200];
    			strcpy(name,a->name);
    			strcpy(dob,a->dob);
    			strcpy(address,a->address);
    			rollNo= a->rollNo;
    			phone= a->phone;
    			
    			
    			a->rollNo=b->rollNo;
    			strcpy(a->name,b->name);
    			strcpy(a->dob,b->dob);
    			strcpy(a->address,b->address);
    			a->phone=b->phone;
    			
    			b->rollNo=rollNo;
    			strcpy(b->name,name);
    			strcpy(b->dob,dob);
    			strcpy(b->address,address);
    			b->phone=phone;
    			
    					   		
    		}
    		b= b->next;	
    	}
    	a= a->next;
    }
}
void modify( struct node* ptr, int option, char newValue[]){

	switch(option){
		case 1:{
			strcpy(ptr->name, newValue);
			break; 
		}
		case 2:{	
    		strcpy(ptr->dob, newValue);
    		break;
		}
		case 3:{
			strcpy(ptr->address, newValue);
			break;
		}
		case 4:{
			long long int temp= atoi(newValue);
    		ptr->phone = temp;
    		break;
		}
    	printf("%s\n", "Failed\n");
    	break;
	}
    printf("%s\n", "Successfully Updated!\n");
}
void modifyPhone( struct node* ptr, int option, long long int newValue){

	ptr->phone = newValue;
   	printf("%s\n", "Successfully Updated!\n");
}
void delete(int rollNo) {	

    struct node* student = search(rollNo);
    if(student == NULL) {
    	printf("%s", "Roll Number not found\n");
	return; 
    }
    
    unusedRollNo[temp]= rollNo;
    temp++;
    
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    
    temp1 = student->prev; 
    temp2 = student->next;
    
    temp1->next = temp2;
    temp2->prev = temp1;
    
    if(student == head){
    	head = NULL;
    }
    free(student);

    printf("%s", "Successfully Deleted!\n");
    
    
}

int main()
{  
 while(1) {
     	int choice;

        printf("%s", "**************MAIN MENU***************\n");
        printf("%s", "1. Insert\n");
        printf("%s", "2. Modify\n");
        printf("%s", "3. Delete\n");
        printf("%s", "4. Sort\n");
        printf("%s", "5. Print\n");

        scanf("%d", &choice);
        
        switch(choice) {
            case 1:{
            	int i = 1 ;
            	char name[100];
                char dob[50];
            	char address[200];
            	long long int phone;
            	
            	char buffer[1024];
            	
            	FILE *file =  fopen("StudentData1.csv","r");
            	fgets(buffer, sizeof(buffer), file);
            	
            	while(i<=13){
            		fgets(buffer, sizeof(buffer), file);
            		char *token = strtok(buffer, ",");
                    
                    token = strtok(NULL, ",");
                    strcpy(name, token);
                    token = strtok(NULL, ",");
                    strcpy(dob, token);
                    token = strtok(NULL, ",");
                    strcpy(address, token);
                    token = strtok(NULL, ",");
                    phone = atoll(token);
                    
                    if(usersAdded == i-1){
                    	if(temp == 0){
                    			
insert(initRollNo,name,dob,address,phone);
                    		initRollNo++;
                    	
                    	}
                    
                    	else{
                    		int newRollNo = unusedRollNo[temp-1];
                       		unusedRollNo[temp-1] = 0;
                         insert(newRollNo , name, dob, address, phone);
                        	temp--;
                        
                    	}
                    	usersAdded++;
			sort();
                    	break;
                    }
					i++;
            	} 
            	printf("%s", "Inserted Successfully\n"); 
             }
             break;
        case 2:{
        
        	int option;
        	int rollNo;
        	char newValue[200];
        	
        	printf("%s\n", "Enter the field to be modified");
        	printf("%s\n", "1. Name");
            	printf("%s\n", "2. Date Of Birth");
            	printf("%s\n", "3. Address");
            	printf("%s\n", "4. Phone Number");
            	scanf("%d", &option);
            	
            	printf("%s\n", "Enter the Roll Number");
        	scanf("%d", &rollNo);
        	getchar();
        	struct node* temp = search(rollNo);
        	
        	if(temp == NULL) {
        		printf("%s", "Roll Number not found\n");
        	 	break;
        	 }
    
        	
        	printf("%s\n", "Enter new value: ");
        	
		if(option != 4){
			fgets(newValue,sizeof(newValue)-1,stdin);
        		*(strchr(newValue,'\n'))='\0';
        		modify(temp,option, newValue);		
		}
		else{
			long long int phone;
			scanf("%lld",&phone);
	        modifyPhone(temp,option, phone);		
		
		}
            
        	break;
        }
        case 3:{
        	int rollNo;
            printf("%s\n", "Enter Roll Number Of Student To Be Deleted: ");
            scanf("%d", &rollNo);
			if(head != NULL){
               	delete(rollNo);
			}
		else{
			printf("%s\n","Nothing to delete");		
		}
        	break;
        }
        case 4:{
        	sortName();
        	break;
        }
        case 5:{
        	print();
        	break;
        }
	    break;
	    }
    }        
	return 0;

}


