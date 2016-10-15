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