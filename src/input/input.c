#include "../includes/quadsolver.h"

/*
 takeInputs function is called in main. It gains input from 
 the command line utilizing a char array and fgets. This is 
 how we get A, B, and C. These floats will then be validated 
 by an outside function. Once validated the float will be 
 send to qsolv.
 */
qInputs 
takeInputs(char* readin)
{
	double a;
	double b;
	double c;
	char* end;

	qInputs inputs;
	char strA[256/3];
	char strB[256/3];
	char strC[256/3];
	char strValidate[256/3]; // Should always be empty
		

	memset(strA, ' ', 256/3);
	memset(strB, ' ', 256/3);
	memset(strC, ' ', 256/3);
	memset(strValidate, ' ', 256/3);

	printf("%s\n", strValidate);

	sscanf(readin, "%s %s %s %s", strA, strB, strC, strValidate);

	inputs.errorCode = 0;
	
	// More than 3 parameters given
	 if (strValidate[0] != ' ') {
	 	// Error
		inputs.errorCode = -5;
		return inputs;
	 }

	a = strtod(strA, &end);
	if(validateInput(strA) != 0) {
		inputs.errorCode = -6;
		return inputs;
	}
	if(a == 0) {
		// Not a quadratic
		inputs.errorCode = -4;
		return inputs;
	}

	b = strtod(strB, &end);
	if(validateInput(strB) != 0) {
		inputs.errorCode = -7;
		return inputs;
	}

	c = strtod(strC, &end);
	if(validateInput(strC) != 0) {
		inputs.errorCode = -8;
		return inputs;
	}

	inputs.a = a;
	inputs.b = b;
	inputs.c = c;
	inputs.errorCode = 0;

	// Return to main to run qsolv
	return inputs;
}