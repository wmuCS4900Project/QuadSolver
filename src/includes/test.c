#include "qsstruct.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>



int main(int argc, char * argv[]){


	qsStruct * s = (qsStruct*)malloc(sizeof(qsStruct));
	s->retVal = 1;
	assert(s->retVal == 1);

	s->a = 5.444;
	assert(fabs(s->a - 5.444) < .0001);

	s->root1 = 5.0 / 2.5;
	assert(s->root1 == 2.0);


	return 0;
	
}