#include <stdlib.h>
#include <stdio.h>

int left=-1,right=-1;
int size=1;
int *queue;

void doubleCapacity(){

    size=size*2;
    queue=(int*)realloc(queue, sizeof(size * sizeof(int)));
}

void halfCapacity(){

    size=size/2;
    queue=(int*)realloc(queue, sizeof(size * sizeof(int)));
}

void insertLeft(int value){
	
	if(left == -1){
		left++;
		right++;
		queue[left] = value;
	}
	else if(size > right+1){
		for(int i=right+1;i>0;i--){
         queue[i]=queue[i-1];
    	}
		queue[0]=value;
		right++;
			
	}
	else{
		doubleCapacity();	
		for(int i=right+1;i>0;i--){
        	queue[i]=queue[i-1];
    	}
		queue[0]=value;
		right++;
	}
	printf("%s\n","Successfully Inserted");
}

void insertRight(int value){

    if(left==-1){
        queue[right]=value;
		left++;
        right++;
        
    }

    else if(size>right+1){
        right++;
        queue[right]=value;
    }

    else{
        doubleCapacity();
        right++;
        queue[right]=value;
    }
	printf("%s\n","Successfully Inserted");
}

void deleteLeft(){
	for(int i=0;i<right;i++){
		queue[i]=queue[i+1];	
	}
	queue[right]=0;
	right--;
	if(size == 2*(right + 1)){
		halfCapacity();
	}
	printf("%s\n","Successfully Deleted");
}

void deleteRight(){
	queue[right]==0;
	right--;
	if(size == 2*(right + 1)){
		halfCapacity();
	}
	printf("%s\n","Successfully Deleted");	
}
void print(){
	printf("Size: %d\n",size);
    for(int i=0;i<=right;i++){
        printf("%d ",queue[i]);
    }
	printf("%s\n","");
    
}
int main(){

	int choice;
	int value;
	
	//initialize the dequeue
	queue= (int*)malloc(sizeof(size * sizeof(int)));

	while(1){
		printf("%s\n","*******Main Menu********");
		printf("%s\n","Please Choose the Option");
		printf("%s\n","1.Insert From Left");
		printf("%s\n","2.Delete From Left");
		printf("%s\n","3.Insert From Right");
		printf("%s\n","4.Delete From Right");
		printf("%s\n","5.Print");		
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("%s\n","Enter Number to Be Entered");
       				scanf("%d",&value);
        			insertLeft(value);
        		break;
			case 2:
				deleteLeft();
        		break;
			case 3:
				printf("%s\n","Enter Number to Be Entered");
       				scanf("%d",&value);
        			insertRight(value);
        		break;
			case 4:
				deleteRight();
        		break;
			case 5:
				print();
        		break;
			default:
				printf("%s\n","Enter A Valid Option");
				break;
		}
	}
	return 0;
}
