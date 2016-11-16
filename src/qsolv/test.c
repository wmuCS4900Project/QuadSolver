#include "../../cunit/cunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../quadsolver.h"
	
int main( ) {
	cunit_init();

	qsStruct q;
	q.a = 1;
	q.b = 2;
	q.c = 1;
  int results = qsolv(&q);
  printf("%d", results);
  assert_eq("ret",q.rootCount, 1);
	assert_feqrerr("Root 1",q.root1, -1.0, 10.0*cunit_dmacheps );
	// Fail this time
	assert_feqrerr("Root 1",q.root1, -1.001, 10.0*cunit_dmacheps );

	q.a = 2;
	q.b = 3;
	q.c = 1;
  results = qsolv(&q);
  assert_eq("ret",q.rootCount, 2);
	assert_feqrerr("Root 1", q.root1, -0.5, 10.0*cunit_dmacheps );
	assert_feqrerr("Root 2",q.root2, -1.0, 10.0*cunit_dmacheps );

	// Fail this time
	assert_feqrerr("Root 1",q.root1, -0.5000001, 10.0*cunit_dmacheps );


  return 0;
}