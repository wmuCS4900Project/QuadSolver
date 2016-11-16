#include "../includes/quadsolver.h"

int
outputErrorVal(int val){

	switch(val){
		case -3:
			printf("Too few arguments, please enter 3 arguments.\n");
			erlog("Too few arguments, please enter 3 arguments.\n");
			break;
		case -4:
			printf("A = 0, not a quadratic equation. A must not be 0.\n");
			erlog("A = 0, not a quadratic equation. A must not be 0.\n");
			break;
		case -5:
			printf("Too many arguments, please enter 3 arguments.\n");
			erlog("Too many arguments, please enter 3 arguments.\n");
			break;
		case -6:
			printf("Variable a is badly formatted. Please enter as 0000.0000.\n");
			erlog("Variable a is badly formatted. Please enter as 0000.0000.\n");
			break;
		case -7:
			printf("Variable b is badly formatted. Please enter as 0000.0000.\n");
			erlog("Variable b is badly formatted. Please enter as 0000.0000.\n");
			break;
		case -8:
			printf("Variable c is badly formatted. Please enter as 0000.0000.\n");
			erlog("Variable c is badly formatted. Please enter as 0000.0000.\n");
			break;
		case -9:
			printf("Determinant is < 0, no roots.\n");
			erlog("Determinant is < 0, no roots.\n");
			break;
		
	}

	return 0;
}

int
outputAnswer(char * out){

	printf("%s\n",out);

	return 0;

}

int erlog(char * msg){

	FILE * fp;
	fp = fopen("log.txt", "a+");
	fprintf(fp, msg);
	if(fp == NULL){
		printf("Can't even log errors! Exiting\n");
		exit(0);
	}
	fclose(fp);

	return 0;
}