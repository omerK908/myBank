#include <stdio.h>
#include <math.h>
#include "myBank.h"

double arr[R_SIZE][C_SIZE]={{0}};
//arr[] => account number
//arr[][] => balance
int openAcc = 0;
void O (){ //open account
	if(openAcc >= 50){
		printf("ERROR: Too many bank accounts \n");
		return;
	}
	int k = -1;
	for(int i = 0; i < C_SIZE; i++){
		if(arr[0][i] == CLOSE){
			k = i;
			i = C_SIZE;
		}
	}
	if (k == -1){
		printf("ERROR: Too many bank accounts \n");
	}
	double m = 0;
	printf("Enter amount: ");
	if(scanf(" %lf", &m) == 1){
		if(m <= 0){
			printf("ERROR: You need to deposit a positive ammount of money \n");
			return;
		}
		arr[0][k] = OPEN;
		arr[1][k] = m;
		printf("Account number is %d now open with %.2lf$\n", k + 901, m);
		openAcc++;
		return;
	}
	printf("Invalid input \n");
}

void B (){ //balance of account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a;
	printf("Enter account: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			printf("Balance of account %d is: %.2lf$ \n", a, arr[1][i]);
		}else return;
	}else printf("Invalid input \n");
}

void D (){ //deposit to account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a;
	printf("Enter account: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			double d;
			printf("Enter ammount to deposit: ");
			if(scanf(" %lf", &d) == 1){			
				if(d < 0){
					printf("Can not deposit negative number \n");
					return;
				}
				arr[1][i] += d;
				printf("Balance of account %d is: %.2lf$ \n", a, arr[1][i]);
			}else printf("Invalid input \n");
		}else return;
	}else printf("Invalid input \n");
	
}
void W (){ //withdraw from account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a = 0;
	printf("Enter account: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			double d;
			printf("Enter ammount to withdraw: ");
			if(scanf(" %lf", &d) == 1){		
				if(d < 0){
					printf("Can not withdraw negative number \n");
					return;
				}else if(d > arr[1][i]){
					printf("ERROR: Cant withdraw more then you have (%.2lf) \n", arr[1][i]);
					return;
				}
				arr[1][i] -= d;
				printf("Balance of account %d is: %.2lf$ \n", a, arr[1][i]);
			}else printf("Invalid input \n");
		}else return;
	}else printf("Invalid input \n");
}

void C (){ //close account
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}
	int a = 0;
	printf("Enter account: ");
	if(scanf(" %d", &a) == 1){
		int i = a - 901;
		if(check(i)){
			arr[0][i] = CLOSE;
			arr[1][i] = 0;
			printf("Account %d is now closed \n", a);
			openAcc--;
		}else return;
	}else printf("Invalid input \n");
}

void I (){ //add interest by %
	if(openAcc == 0){
		printf("ERROR: All accounts are closed \n");
		return;
	}else{
		double a;
		printf("Enter interest: ");
		if(scanf(" %lf", &a) == 1){
			if(a < 0){
				printf("Cannot interest negative number \n");
				return;
			}
			a = a / 100;
			for(int i = 0; i < C_SIZE; i++){
				if(arr[0][i] == OPEN){
						arr[1][i] += (arr[1][i] * a);
				}
			}
			a *= 100;
			printf("Interest of %.2lf", a);
			printf(" has been added. \n");
		}else printf("Invalid input \n");
	}
}
void P (){ //print all open accounts
	if (openAcc == 0){
		printf("Nothing to print \n");
	}else{
		int counter = 0;
		for(int i = 0; i < C_SIZE; i++){
			if(arr[0][i] == OPEN){
				counter++;
				printf("[%d]: %.2f$", i + 901, arr[1][i]);
				if(counter < openAcc) printf(", ");
			}
		}
		printf("\n");
	}
}

void E (){
	openAcc = 0;
	for (int i = 0; i < C_SIZE; i++){
		arr[0][i] = 0;
		arr[1][i] = 0;
	}
	printf("Exiting program \n");
}

_Bool check (int i){
	if (i < 0 || i > 49){
		printf("Error: Invalid account number \n");
		return 0;
	}
	if(!isOpen (i)){
		printf("Error: Account is closed \n");
		return 0;
	}
	return 1;
}

_Bool isOpen (int i){
	if(arr[0][i] == CLOSE){
		return 0;
	}return 1;
}