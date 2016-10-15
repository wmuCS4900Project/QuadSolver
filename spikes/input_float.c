#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validateInput(double digit, char* token, char* end);
int validateDigits(char* strDigits);

/*Read in inputs while there are inputs in file given in command line input */
int main(int argc, char * argv[]){
	
	if(argc < 2){
		printf("No filename included\n");
		return -1;
	}

	FILE * fp;

	if(!(fp = fopen(argv[1],"r"))) return -1;
	
	//char * readin = malloc(100);
	char * token;
	double a, b, c;
	char readin[256];
	char* end;

	while(fgets(readin,sizeof(readin),fp)){

		char strA[256];
		char strB[256];
		char strC[256];

		memset(strA, ' ', 256);
		memset(strB, ' ', 256);
		memset(strC, ' ', 256);

		sscanf(readin, "%s %s %s", strA, strB, strC);
		
		a = strtod(strA, &end);
		if(validateInput(strA) == 0)
			continue;

		b = strtod(strB, &end);
		if(validateInput(strB) == 0)
			continue;

		c = strtod(strC, &end);
		if(validateInput(strC) == 0)
			continue;

		//printf("found %lf %lf %lf \n",a,b,c);

		//call qsolv
	}

	fclose(fp);
	
	return 0;
}

/**
* Validate that the input is actually a float. 
* @param numAsString -- the char* that is being
* converted to a double
*/

int validateInput(char* numAsString) {
	char* end;
	double num = strtod(numAsString, &end);

	if( end == numAsString || validateDigits(numAsStringen) == 0) {
		// a conversion was not performed
		printf("%s Is not a valid number\n", token );
		return 0;
	} 
	return 1;
}

/*
* Validate each digit of a string, to make 
* sure a number is being supplied
* char* strDigits--String containing a number
**/
int validateDigits(char* strDigits) {
	for(int i=0; i < sizeof(strDigits); i++) {
		//printf("%c", strDigits[i]);
		if (strDigits[i] == ' ')
			return 1;
		if (isdigit(strDigits[i]) == 0 && strDigits[i] != '.' && strDigits[i] != '\0') {
			return 0;
		}
	}
	return 1;
}
