// qsolve_sqrt.c
// qsolve_sqrt() is a wrapper for the sqrt function
// This allows:
//   both testing of the system with a mock object
//   easy replacement with a new square root fiunction
//   checking for validity of arguements
//   possible logging of all calls or errors to mysqrt
//
//   MY BAD, Thess comments shoud include
//   wehat this does
//      inputs
//      outputs
//      reurn values and errors

#include <math.h>
#include "qsolve_sqrt.h"

double qsolve_sqrt(double x) {
if(x < 0){
  return -1.0;
}
return sqrt(x);
}
