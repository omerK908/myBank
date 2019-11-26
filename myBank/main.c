#include <stdio.h>
#include "myBank.h"


int main(){
	char operator = ' ';
	while (operator != 'E'){
		printf("Transaction type (O, B, D, W, C, I, P, E): ");
		scanf(" %c", &operator);
		switch(operator){
			case 'O':
            	O();
            	break;
        	case 'B':
            	B();
            	break;
        	case 'D':
            	D();
            	break;
        	case 'W':
				W();
            	break;
			case 'C':
				C();
            	break;
			case 'I':
				I();
            	break;
			case 'P':
				P();
            	break;
			case 'E':
				E();
				return 0;
            	break;
			default:
				printf("Error! operator is invalid \n");
		}
	}
	return 0;
}