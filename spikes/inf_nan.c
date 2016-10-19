/*
	Note--need to compile with std=c99
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int testValues(double testValue, char* valueName); 

int main() {
	double a = NAN;
	double b = INFINITY;
	testValues(a, "A");
	testValues(b, "B");

	// Test Divide by 0
	double top = 15;
	double bottom = 0;

	a = NAN;
	b = INFINITY;

	a = top/bottom; // A in an inf
	testValues(a, "A");
	a = top/5; // A is not an inf
	testValues(a, "A");

	// Test Square root negative
	b = sqrt(-5);
	testValues(b, "B"); // B is a nan

	// TODO: SQRT of NAN, INF, -NAN, -INF

	a = pow(45, 499445);
	testValues(a, "A"); // A is an inf

	a = 0;
	a = pow(455341848593, 2);
	testValues(a, "A"); // A is an inf
}

/*
	Some results:
	------------------------------------------------
	-Divide by 0 returns an inf
	-Square root of a negative number returns a nan
	-Exponent of a really big number returns an inf
	-Really big number squared returns an inf

	In validation, we can check after each calculation 
	if the answer will return an inf or a nan. This way
	we can tell the user exactly where the equation went 
	wrong.

	One precaution we can take is to check if a=0 when
	it is supplied, because that will always give us an
	inf.
*/

int testValues(double testValue, char* valueName) {
	if (isnan(testValue)) { 
		printf("%s is a NAN\n", valueName);
		return -1;
	}

	if(isinf(testValue)) {
		printf("%s is an inf\n", valueName);
		return -1;
	}
	return 0;
	printf("\n");
}
