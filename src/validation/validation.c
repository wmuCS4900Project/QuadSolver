#include "../quadsolver.h"

/*
* Validate that the input is actually a float. 
* @param numAsString -- the char* that is being
* converted to a double
*/
int 
validateInput(char* numAsString) {
	char* end;
	double num = strtod(numAsString, &end);
	int valid = 0;

	if( end == numAsString || validateDigits(numAsString) != 0) {
		// a conversion was not performed
		printf("%s Is not a valid number\n", numAsString );
		return -1;
	} 
	return 0;
}

/*
* Validate each digit of a string, to make 
* sure a number is being supplied
* char* strDigits--String containing a number
**/
int 
validateDigits(char* strDigits) {
	//for(int i=0; i <= sizeof(strDigits); i++) {
	int i = 0;
	while(strDigits[i] != '\0'){
		//printf("%c\n", strDigits[i]);
		printf("%d\n",i);
		if (strDigits[i] == ' ')
			return 0;
		if (isdigit(strDigits[i]) == 0 && strDigits[i] != '.' && strDigits[i] != '\0') {
			return -1;
		}
		i++;
	}
	return 0;
}

char *
remove_newline(char *s)
{
    int len = strlen(s);

    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
            // if there's a newline, truncate the string

    return s;
}