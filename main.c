#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define SIZE 2
#define FLOC "//home//kizna//Documents//projects//receipt.txt" //ubah

int member_id[SIZE] = {2019, 2018};
int ans4, ans2, days;
char a;
float discount = 0.1, price = 0.0, final_price = 0.0;

int gets_song(){
pid_t x;

	x = fork ();

	if (x<0){
		puts("fork failure");
		exit(-1);
	}
	else if (x==0){
		system("mpg123 -q /home/kizna/Downloads/EDsong.mp3"); //ubah
	exit(0);
	}
	else{ printf("from parent:mpg123 is pid %d\nPlease enjoy the song while we redirect you to the parcel sending service\n",x);
	}
}

int current_time(){
	time_t rawtime;
	struct tm*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date :%s",asctime(timeinfo));
	return 0;
}

void gets_menu(){
	int i = 0;
	do{
		printf("1---International\n");
		printf("2---Domestic\n");
		printf("Please choose between International or Domestic Parcel Service.\n");
		scanf("%d", &i);
	}while(i < 1 || i > 2);
	printf("You choose : %d\n", i);
}

int gets_integer(){
	int input;
	int i;

		printf("Enter id :");
		scanf("%d", &input);

		for(i =0; i < 2; i ++)
			if(member_id[i] == input){
				final_price = (price - (price * discount));
				break;
			}
			else{
				final_price = price;
			}
		return final_price;
}

int get_switch(){
	printf("Choose one of the following type of parcel.\n");
	printf("F------FOOD\n");
	printf("C------CLOTHES\n");
	printf("B------BOOKS\n");
	printf("A------ALL\n");
	scanf(" %c", &a);
	switch (a)
	{
	case 'F' :
		price = 10000.0;
		days = 2;
		break;
	case 'C' :
		price = 5000.0;
		days = 3;
		break;
	case 'B' :
		price = 3000.0;
		days = 3;
		break;
	case 'A' :
		price = 10000.0;
		days = 2;
		break;
	default :
		printf("Choose one of the following only.");
		break;
	}
	printf("You choose :%c\n", a);
	printf("the price will be : %0.2f$ \n", price);
	printf("And it will take :%d days \n", days);
	printf("---------------------------\n");
	return a;
}
	
	
int main (void){
        
	char ans1;
	char name[100];
	char address[100];
	char weight[100];
	gets_song();
        FILE *mehh;
        mehh = fopen(FLOC, "w");
	printf("----------------------------------------\n");
	printf("    ONLINE PARCEL DELIVERY PROGRAMME    \n");
	printf("----------------------------------------\n");
	printf("             MEGA SALE                  \n");
	printf("    Today's Coupon code : JKLE4         \n");
	printf("----------------------------------------\n");
	printf("  *we send parcel to your loved ones* \n");
	printf("****************************************\n");
	printf("   FOODS         BOOKS         CLOTHES  \n");
	printf("      OR EVEN COMBINE ALL OF THEM       \n");
	printf("****************************************\n");
	current_time();
	printf("Do u want to start sending parcel? (Y or N)\n");
	scanf("%c", &ans1);

	if(ans1 == 'Y')
	{
		gets_menu();
		get_switch();
	
		printf("Are you a member?\n");
		printf("1---for YES\n");
		printf("2---for NO\n");
		scanf("%d", &ans2);

		if(ans2 == 1) {
			gets_integer();
			printf("Final Price :%0.2f$\n", final_price);
		}
		else
			printf("Final Price :%0.2f$\n", price);
		printf("Input Your Name :\n");
		scanf("%99s",name);
		printf("Input Your Address :\n");
		scanf("%99s",address);
		printf("Input The Weight (kg) :\n");
		scanf("%99s",weight);
		printf("Your Information has been delivered\n");
		printf("Do you want exit?\n");
		printf("1---for YES\n");
		printf("2---for NO\n");
		scanf("%d", &ans4);

		if (ans4 == 1) {
			printf("-------------------------------------------\n");
			printf("             Printed receipt               \n");
			printf("-------------------------------------------\n");
			printf("Name :%s \nAddress :%s \nWeight :%s \n",name,address,weight);
			printf("Your Information is as stated above  \n");
			if ( ans2 ==1) {
				printf("Final price : %0.2f$\n", final_price);
			}
			else
				printf("Final price :%0.2f$\n", price);
			printf("Type of parcel chose : %c\n", a);
			printf("The lorry will come and pick your parcel tomorrow \n");
			printf("------------------------------------------\n");
	                fprintf(mehh,"===========================================\n");
                        fprintf(mehh,"     ONLINE PARCEL DELIVERY PROGRAMME    \n");
                        fprintf(mehh,"    *we send parcel to your loved ones* \n");
	                fprintf(mehh,"===========================================\n");

			fprintf(mehh,"-------------------------------------------\n");
			fprintf(mehh,"           Electronic receipt                  \n");
			fprintf(mehh,"-------------------------------------------\n");
                       	time_t rawtime;
	                struct tm*timeinfo;

	                time(&rawtime);
	                timeinfo = localtime(&rawtime);
	                fprintf(mehh,"Time/Date :%s",asctime(timeinfo));

			fprintf(mehh,"Name :%s \nAddress :%s \nWeight : %skg \n",name,address,weight);
			if ( ans2 ==1) {
				fprintf(mehh,"Price : %0.2f$\n", final_price);
			}
			else
				fprintf(mehh,"Price :%0.2f$\n", price);
			fprintf(mehh,"Parcel Type Chose : %c\n", a);
			fprintf(mehh,"------------------------------------------\n");
		}
		else
                {
			printf("Okay then you have to start again: ");
                }
	}
	else
        {
		printf("Thank you for choosing us. Till we meet again.");
                fclose(mehh);
        }
}

