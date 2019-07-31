#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int **red;
int **blue;
int **green;

int p= 953, q= 1268;

void readRedFile(){

	char buffer[12000];
	char *ptr;
	int i=0,j=0;

	FILE *temp = fopen("Q3_ip_Red.dat", "r");
	while(fgets(buffer,12000,temp) !=  NULL){
	 	ptr= strtok(buffer,",");
	 	for(int l=0; l < 6000 ;l++){
	 		if(ptr != NULL){
	 			red[i][j]= atoi(ptr);
	 			j++;
	 		}
	 		ptr = strtok(NULL, ",");
	 		if(j==q){
	 			j=0;
	 			i++;
	 		}
	 		if(i==p){
	 			break;
	 		}
	 	}
	}
}

void readBlueFile(){

	char buffer[12000];
	char *ptr;
	int i=0,j=0;

	FILE *temp = fopen("Q3_ip_Blue.dat", "r");
	while(fgets(buffer,12000,temp) !=  NULL){
	 	ptr= strtok(buffer,",");
	 	for(int l=0; l<6000 ;l++){
	 		if(ptr != NULL){
	 			blue[i][j]= atoi(ptr);
	 			j++;
	 		}
	 		ptr = strtok(NULL, ",");
	 		if(j==q){
	 			j=0;
	 			i++;
	 		}
	 		if(i==p){
	 			break;
	 		}
	 	}
	}
}

void readGreenFile(){

	char buffer[12000];
	char *ptr;
	int i=0,j=0;

	FILE *temp = fopen("Q3_ip_Green.dat", "r");
	while(fgets(buffer,12000,temp) !=  NULL){
	 	ptr= strtok(buffer,",");
	 	for(int l=0; l<6000 ;l++){
	 		if(ptr != NULL){
	 			green[i][j]= atoi(ptr);
	 			j++;
	 		}
	 		ptr = strtok(NULL, ",");
	 		if(j==q){
	 			j=0;
	 			i++;
	 		}
	 		if(i==p){
	 			break;
	 		}
	 	}
	}
}

void removeRed(){
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++) {
			
			int *R = &red[i][j];
			int G = green[i][j];
			int B = blue[i][j];

			if(*R > G && *R > B) *R = 0;  
		}
	}
}

void removeBlue(){
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++) {
			
			int R = red[i][j];
			int G = green[i][j];
			int *B = &blue[i][j];

			if(*B > R && *B > G) *B = 0;  
		}
	}
}

void removeGreen(){
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++) {
			
			int R = red[i][j];
			int *G = &green[i][j];
			int B = blue[i][j];

			if(*G > R && *G > B) *G = 0;       
		}
	}
}

void print(int value) {

	if(value == 1) {
		for(int i = 0; i < p; i++)
			for(int j = 0; j < q; j++) {
				printf("%d ", red[i][j]);
			}
	}
	
	else if(value == 2) {
		for(int i = 0; i < p; i++)
			for(int j = 0; j < q; j++) {
				printf("%d ", green[i][j]);
			}
	}

	else if(value == 3) {
		for(int i = 0; i < p; i++)
			for(int j = 0; j < q; j++) {
				printf("%d ", blue[i][j]);
			}
	}

	else {
		printf("Wrong color component!!");
	}
	putchar('\n');
}
void redOnly() {
	
	for(int i = 0; i < p; i++)
		for(int j = 0; j < q; j++) {
			int R = red[i][j];
			int *G = &green[i][j];
			int *B = &blue[i][j];

			if(*B > R && *B > *G) *B = 0;  
			else if(*G > R && *G > *B) *G = 0;   
		}
}
void blueOnly() {
	
	for(int i = 0; i < p; i++)
		for(int j = 0; j < q; j++) {
			int *R = &red[i][j];
			int *G = &green[i][j];
			int B = blue[i][j];

			if(*R > B && *R > *G) *R = 0;  
			else if(*G > *R && *G > B) *G = 0;   
		}
}
void greenOnly() {
	
	for(int i = 0; i < p; i++)
		for(int j = 0; j < q; j++) {
			int *R = &red[i][j];
			int G = green[i][j];
			int *B = &blue[i][j];

			if(*R > *B && *R > G) *R = 0;  
			else if(*B > *R && *B > G) *B = 0;   
		}
}
void pixelValue(int x, int y){
	
	printf("Red: %d\n", red[x][y]);
	printf("Blue: %d\n", blue[x][y]);
	printf("Green: %d\n", green[x][y]);
}

void initFiles(){

	red = (int **)malloc(q * sizeof(int *));

    for (int k=0; k<q; k++){
         red[k] = (int *)malloc(p * sizeof(int));
	}

	blue = (int **)malloc(q * sizeof(int *));

    for (int k=0; k<q; k++){
         blue[k] = (int *)malloc(p * sizeof(int));
	}
	
	green = (int **)malloc(q * sizeof(int *));

    for (int k=0; k<q; k++){
         green[k] = (int *)malloc(p * sizeof(int));
	}
	readRedFile();
	readBlueFile();
	readGreenFile();
}
int main(){

	int choice;
	initFiles();

	while(1){

		printf("*******MAIN MENU********\n");
	
		printf("%s", "1. Remove All Red Shades\n");
   		printf("%s", "2. Remove All Green Shades\n");
   		printf("%s", "3. Remove Blue Shades\n");
   		printf("%s", "4. RedOnly\n");
    	printf("%s", "5. GreenOnly\n");
    	printf("%s", "6. BlueOnly\n");
		printf("%s", "7. Pixel Value\n");
		printf("%s", "8. Print Pixel Value of Colors\n");
	
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				removeRed();
				break;
			case 2:
				removeGreen();
				break;
			case 3:
				removeBlue();
				break;
			case 4:
				redOnly();
				break;
			case 5:
				blueOnly();
				break;
			case 6:
				greenOnly();
				break;
			case 7:{
				int x,y;

				printf("%s\n","Enter X Coordinate");
				scanf("%d", &x);

				printf("%s\n","Enter Y Coordinate");
				scanf("%d", &y);	

				pixelValue(x,y);
				}
				break;
			case 8: {
				printf("Which component you want to print:\n");
				printf("1.Red / 2.Green / Blue\n");
				int option;
				scanf("%d", &option);
				print(option);
				break;
			}
		}
	
	}
		
	return 0;
}
