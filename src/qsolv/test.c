#include "../../cunit/cunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../quadsolver.h"
	
int main( ) {
	cunit_init();

  qsStruct results = qsolve(1, 2, 1);
  assert_eq("ret",results.rootCount, 1);
	assert_feqrerr("x1",results.root1, -1.0, 10.0*cunit_dmacheps );
	// Fail this time
	assert_feqrerr("x1",results.root1, -1.001, 10.0*cunit_dmacheps );


  results = qsolve(2, 3, 1);
  assert_eq("ret",results.rootCount, 2);
	assert_feqrerr("x1",results.root1, -0.5, 10.0*cunit_dmacheps );
	assert_feqrerr("x1",results.root2, -1.0, 10.0*cunit_dmacheps );

	// Fail this time
	assert_feqrerr("x1",results.root1, -0.5000001, 10.0*cunit_dmacheps );


  return 0;
}