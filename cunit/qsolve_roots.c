// qsolve_roots.c 
// version 1.01
// Needs testing. written to address best prescision results
// // or non-regular IEEE fp inoput or results.
// 
// MY BAD. These comments should include 
//  What this does:
//       inputs
//       outputs
//       return value and errors
//       side evvects
//
#include <stdio.h>
#include "qsolve_roots.h"
#include "qsolve_sqrt.h"

//X quadratic eqaution solver
//X does not check for overflows and underflows.

int qsolve_roots(Coef *coef, Root *root) {
double a,b,c;  // coefs of quadratic , LOCAL COPIES 
double d;      // discriminate d = b^2 = 4ac
double sqrtd; // sqrt of d;

#ifdef DEBUG 
fprintf(stderr,"DEBUG Entering qsolve_roots\n");
fprintf(stderr,"DEBUG a= %20.12f   b = %20.12f   c = %20.12f\n",
     coef->a, coef->b, coef->c);
#endif

a = coef->a;
b = coef->b;
c = coef->c;

if(a == 0.0) { // not a true quadratic
  return -1 ;
} 

d = b*b - 4.0*a*c;
if(d < 0.0) { // No real roots 
  return -2;
}
if(d == 0) { // double root 
  root->x1 = -b / (2.0*a);
  root->x2 = root->x1; 
  return 1;
}
// two roots 
sqrtd = qsolve_sqrt(d);
root->x1 = (-b + sqrtd)/(2.0*a);
root->x2 = (-b - sqrtd)/(2.0*a);

#ifdef DEBUG
fprintf(stderr,"DEBUG Exiting qsolve_roots return 2\n");
#endif

return 2;
}
