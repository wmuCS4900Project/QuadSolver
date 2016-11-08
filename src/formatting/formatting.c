#include <stdio.h>
#include "../includes/qsstruct.h"
#include "../output/output.c"

int formatAnswer(qsStruct * ans){

	if(ans->rootCount == 1){

		char * ans = malloc(sizeof(char) * 200);
		strcpy(ans, "The quadratic equation with values a = %f, b = %f, and c = %f has one roots. Root 1 = %f.\n",
			ans->a,ans->b,ans->c,ans->root1);
		if(outputAnswer(ans) != 0){
			return -1;
		}
		else return 0;
	}
	else if(ans->rootCount == 2){
		char * ans = malloc(sizeof(char) * 200);
		strcpy(ans, "The quadratic equation with values a = %f, b = %f, and c = %f has two roots. Root 1 = %f, Root 2 = %f.\n",
			ans->a,ans->b,ans->c,ans->root1,ans->root2);
		if(outputAnswer(ans) != 0){
			return -1;
		}
		else return 0;
	}
	else
		return -1;

}