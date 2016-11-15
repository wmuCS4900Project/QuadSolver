#include "../../cunit/cunit.h"
#include "../includes/quadsolver.h"


int testnum;
int outputAnswer(char * out);

	
int main(int argc, char * argv[]){

	cunit_init();
	qInputs ret;
	char * s;

//test 1
	s = "4.0 5.5 6.0";
	ret = takeInputs(s);
	assert_eq("input1",ret.errorCode,0);

//test 2
	s = "4.5 f.5 7.6";
	ret = takeInputs(s);
	assert_eq("input2",ret.errorCode,-7);

//test 3
	s = "0 5.5 1 2432";
	ret = takeInputs(s);
	assert_eq("input2",ret.errorCode,-5);

//test 4
	s = "4.5 5.5 7.f6";
	ret = takeInputs(s);
	assert_eq("input2",ret.errorCode,-8);

//test 5
	s = "4.& 5.5 7.6";
	ret = takeInputs(s);
	assert_eq("input2",ret.errorCode,-6);


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