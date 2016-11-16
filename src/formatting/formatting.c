#include "../includes/quadsolver.h"

int formatAnswer(qsStruct * ans);


/*This function is called from main.
It takes the answer struct and formats it for output,
and then calls the output function, passing the formatted string along
It returns a 0 if everything works properly, a -1 otherwise.*/
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