#include "../../cunit/cunit.h"
#include "../includes/quadsolver.h"


int testnum;
int outputAnswer(char * out);

	
int main(int argc, char * argv[]){

	cunit_init();

//test 1
	testnum = 1;
	qsStruct * q = malloc(sizeof(qsStruct));
	q->a = 3.0;
	q->b = 4.0;
	q->c = 5.0;
	q->root1 = 6.0;
	q->root2 = 7.0;
	q->rootCount = 2;
	int ret = formatAnswer(q);
	assert_eq("ret",ret,0);
	free(q);

//test 2
	testnum = 2;
	qsStruct * q2 = malloc(sizeof(qsStruct));
	q2->a = 45.0;
	q2->b = 22.55;
	q2->c = 5.009;
	q2->root1 = 62.022221;
	q2->root2 = 7.999938;
	q2->rootCount = 2;
	int ret2 = formatAnswer(q2);
	assert_eq("ret2",ret2,0);
	free(q2);


}

int outputAnswer(char * out){

	if(testnum == 1){
		char * str = malloc(sizeof(char) * 100);
		strcpy(str,"The quadratic equation with values a =  3.00, b =  4.00, and c =  5.00 has two roots. Root 1 = 6.00000, Root 2 = 7.00000.\n");
		//printf("Comparing the following two strings: \n");
		//puts(str);
		//puts(out);
		int ret = strcmp(str,out);
		assert_eq("in",ret,0);
		return 0;
	}

	if(testnum == 2){
		char * str = malloc(sizeof(char) * 100);
		strcpy(str,"The quadratic equation with values a = 45.00, b = 22.55, and c =  5.01 has two roots. Root 1 = 62.02222, Root 2 = 7.99994.\n");
		//printf("Comparing the following two strings: \n");
		//puts(str);
		//puts(out);
		int ret = strcmp(str,out);
		assert_eq("in",ret,0);
		return 0;
	}

}