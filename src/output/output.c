#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/qsstruct.h"

int outputErrorVal(int val, int loc);
int outputAnswer(char * out);
int erlog(char * msg, int loc);

int
outputErrorVal(int val, int loc){

	switch(val){
		case 1:
			printf("loss of precision\n");
			erlog("loss of precision\n", loc);
			quit();
			break;
		case 2:
			printf("Not a quadratic equation");
			quit();
			break;
	}

}

int
outputAnswer(char * out){

	printf("%s\n",out);

	return 0;

}

int erlog(char * msg, int loc){

	FILE * fp;
	fp  = fopen("log.txt", "w+");

	if(fp == NULL){
		printf("Can't even log errors! Exiting\n");
		exit(0);
	}

}