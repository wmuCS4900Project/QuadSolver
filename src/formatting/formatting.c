#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/qsstruct.h"

int formatAnswer(qsStruct * ans);

int 
formatAnswer(qsStruct * ans){

	if(ans->rootCount == 1){
		size_t size = sizeof(char) * 200;
		char * out = malloc(size);
		snprintf(out, size,"The quadratic equation with values a = %5.2f, b = %5.2f, and c = %5.2f has one roots. Root 1 = %5.5f.\n",
			ans->a,ans->b,ans->c,ans->root1);
		if(outputAnswer(out) != 0){
			return -1;
		}
		else return 0;
	}
	else if(ans->rootCount == 2){
		size_t size = sizeof(char) * 200;
		char * out = malloc(size);
		snprintf(out, size,"The quadratic equation with values a = %5.2f, b = %5.2f, and c = %5.2f has two roots. Root 1 = %5.5f, Root 2 = %5.5f.\n",
			ans->a,ans->b,ans->c,ans->root1,ans->root2);
		if(outputAnswer(out) != 0){
			return -1;
		}
		else return 0;
	}
	else
		return -1;

}