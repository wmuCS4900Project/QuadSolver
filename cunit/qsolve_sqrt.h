// qsolve_sqrt.h
// qsolve_sqrt() is a wrapper for the sqrt function
// This allows:
//   both testing of the system with a mock object
//   easy replacement with a new square root fiunction
//   checking for validity of arguements
//   possible logging of all calls or errors to mysqrt

double qsolve_sqrt(double x);

