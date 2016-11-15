#include "../../cunit/cunit.h"
#include "../includes/quadsolver.h"


int testnum;
int outputAnswer(char * out);
	
int main(int argc, char * argv[]){

	cunit_init();

	// All wrong
	char * test1 = "42300412432 43214235324 FaFererER";
	printf("Testing %s\n",test1);
	qInputs in1 = takeInputs(test1);

	assert_eq("T1: errorCode", in1.errorCode, -8);


	// First wrong
	char * test2 = "jk 43.4 4378978977889";
	printf("Testing %s\n",test2);
	qInputs in2 = takeInputs(test2);

	assert_eq("T2: errorCode", in2.errorCode, -6);


	// Second wrong
	char * test3 = "2345.4 434e.4 7433.54";
	printf("Testing %s\n",test3);
	qInputs in3 = takeInputs(test3);

	assert_eq("T3: errorCode", in3.errorCode, -7);


	// Third wrong
	char * test4 = "0.0 43.4 43789758977889";
	printf("Testing %s\n",test4);
	qInputs in4 = takeInputs(test4);

	assert_eq("T4: errorCode", in4.errorCode, 0);


	// All Right, too many parameters
	char * test5 = "3 43.4 4378978977889 4";
	printf("Testing %s\n",test5);
	qInputs in5 = takeInputs(test5);

	assert_eq("T5: errorCode", in5.errorCode, -5);

	// All Right
	char * test6 = "3 43.4 4378978977889";
	printf("Testing %s\n",test6);
	qInputs in6 = takeInputs(test6);

	assert_eq("T6: errorCode", in6.errorCode, 0);

}

int 
validateInput(char* numAsString) {
	char* end;
	double num = strtod(numAsString, &end);
	int valid = 0;

	if( end == numAsString || validateDigits(numAsString) != 0) {
		//printf("%s Is not a valid number\n", numAsString );
		return -1;
	} 
	return 0;

}

int 
validateDigits(char* strDigits) {
	//for(int i=0; i <= sizeof(strDigits); i++) {
	int i = 0;
	while(strDigits[i] != '\0'){
		//printf("%c\n", strDigits[i]);
		//printf("%d\n",i);
		if (strDigits[i] == ' ')
			return 0;
		if (isdigit(strDigits[i]) == 0 && strDigits[i] != '.' && strDigits[i] != '\0') {
			return -1;
		}
		i++;
	}

	return 0;
}