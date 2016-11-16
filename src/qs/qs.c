/* This program will read floats from command line inputs or read from a file
in order to solve the quadratic equation. Inputs are taken in float form and 
calculated using double precision to IEEE standard.*/
#include "../quadsolver.h"

int 
main(int argc, char * argv[])
{
	int ret;

	while(ret != 1){
		ret = loop();
	}
}

/*
* Separate function to loop so we can reenter and continue to request inputs.
*/
int
loop(){
	qInputs input;
	qsStruct q;
	char readin[256];
	int ret;

	printf("Please enter a,b, and c separated by spaces\n (i.e., <a> <b> <c>) or \"q\" to quit\n");
	//Inputs from command line
	fgets(readin,sizeof(readin), stdin))

	// Quit command
	if(strA[0] == 'q' ) {
		printf("Quitting...\n");
		return 1;
	}

	//Parse out inputs
	input = takeInputs(readin);
	if (input.errorCode != 0) {
		// Raise error
		// Output should handle error code
		outputErrorVal(input->errorCode);
		return 0; 
	}
	
	//No error? good
	printf("Running qsolve for a=%d, b=%d, c=%d", input.a, input.b, input.c);
	
	q.a = input.a;
	q.b = input.b;
	q.c = input.c;

	//run Qsolv
	ret = qssolv(&q);
	if(ret != 0){
		// Raise error
		// Output should handle error code
		outputErrorVal(input->errorCode);
		return 0; 
	}

	//format and output results
	if(q.rootCount <= 0){
		outputErrorVal(q.rootCount);
	}

	ret = formatting(&q);
	if(ret != 0){
		// Raise error
		// Output should handle error code
		outputErrorVal(input->errorCode);
		return 0; 
	}

	//end

	return 0;
}