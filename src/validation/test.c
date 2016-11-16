#include "../../cunit/cunit.h"
#include "../includes/quadsolver.h"
	
int main(int argc, char * argv[]){

	cunit_init();



//validate digits tests
	char * test1 = "A042300412432";
	//printf("Testing %s\n",test1);
	int ret1 = validateDigits(test1);
	assert_eq("dig",ret1,-1);

	char * test2 = "04321423k5324";
	//printf("Testing %s\n",test2);
	int ret2 = validateDigits(test2);
	assert_eq("dig",ret2,-1);

	char * test3 = "FaFererER";
	//printf("Testing %s\n",test3);
	int ret3 = validateDigits(test3);
	assert_eq("dig",ret3,-1);

	char * test4 = "45242323";
	//printf("Testing %s\n",test4);
	int ret4 = validateDigits(test4);
	assert_eq("dig",ret4,0);

	char * test5 = "4524232363447433r";
	//printf("Testing %s\n",test5);
	int ret5 = validateDigits(test5);
	assert_eq("dig",ret5,-1);

	char * test6 = "-4524232363447433";
	//printf("Testing %s\n",test5);
	int ret6 = validateDigits(test6);
	assert_eq("dig",ret6,0);




//validate input tests

	int ret;
	char * test;

	test = "A042300412432";
	ret = validateInput(test);
	assert_eq("input",ret,-1);

	test = "04321423k5324";
	ret = validateInput(test);
	assert_eq("input",ret,-1);

	test = "FaFererER";
	ret = validateInput(test);
	assert_eq("input",ret,-1);

	test = "45242323";
	ret = validateInput(test);
	assert_eq("input",ret,0);

	test = "4524232363447433r";
	ret = validateInput(test);
	assert_eq("input",ret,-1);

	test = "444999.42423";
	ret = validateInput(test);
	assert_eq("input",ret,0);

	test = "0.0";
	ret = validateInput(test);
	assert_eq("input",ret,0);

	test = "-10.0";
	ret = validateInput(test);
	assert_eq("input",ret,0);



return 0;
}