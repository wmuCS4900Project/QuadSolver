#include "../quadsolver.h"

/*
 takeInputs function is called in main. It gains input from 
 the command line utilizing a char array and fgets. This is 
 how we get A, B, and C. These floats will then be validated 
 by an outside function. Once validated the float will be 
 send to qsolv.
 */
int 
takeInputs()
{
	char readin[256];
	double a;
	double b;
	double c;
	char* end;

	char strA[256/3];
	char strB[256/3];
	char strC[256/3];
	char strValidate[256/3]; // Should always be empty
		
	printf("Please enter a,b, and c separated by spaces\n (i.e., <a> <b> <c>)\n");

	while(fgets(readin,sizeof(readin), stdin)){
		memset(strA, ' ', 256/3);
		memset(strB, ' ', 256/3);
		memset(strC, ' ', 256/3);
		memset(strValidate, ' ', 256/3);

		sscanf(readin, "%s %s %s %s", strA, strB, strC, strValidate);
		
		// More than 3 parameters given
		 if (strValidate[0] != ' ') {
		 	// Error
		 	printf("Error: No many arguments supplied. Please try again: \n");
		 	continue;
		 }

		// Quit command
		if(strA[0] == 'q' ) {
			printf("Quitting...\n");
			break;
		}

		a = strtod(strA, &end);
		if(validateInput(strA) != 0)
			continue;

		b = strtod(strB, &end);
		if(validateInput(strB) != 0)
			continue;

		c = strtod(strC, &end);
		if(validateInput(strC) != 0)
			continue;

		printf("Running qsolve for input a=%lf b=%lf c=%lf... \n", a, b, c);
		//call qsolv

		// continue loop
		printf("Please enter a,b, and c separated by spaces\n (i.e., <a> <b> <c>)\n");

	}
	return 0;
}

/*
 May not use this function -- just use redirection instead. 
*/

// int 
// runFile(char * fname)
// {
// 	FILE * fp;
    
// 	if(!(fp = fopen(fname,"r"))) return -1;
	
// 	char * token;
// 	float a, b, c;
// 	char readin[256];

// 	while(fgets(readin,sizeof(readin),fp))
//     {
// 		token = strtok(readin," ");
// 		a = atof(token);
// 		token = strtok(NULL," ");
// 		b = atof(token);
// 		token = strtok(NULL," ");
// 		c = atof(token);

// 		printf("found %5.5f %5.5f %5.5f \n",a,b,c);
//         //call validate(? may be moved to main)
//         //call qsolv(? may be moved to main)
// 	}

// 	fclose(fp);

// 	return 0;

// }