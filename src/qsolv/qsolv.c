#include <math.h>
#include "../includes/quadsolver.h"


int qsolv(qsStruct *results)
{
  double d,root1,root2; 

  d = getDeterminant(results);
     
  if(d < 0){
    // no real roots
    results->rootCount = -9;
    return 0; 
  }

  else if (isinf(d)) {
    results->rootCount = -10;
  }

  else if(d==0){
   // One root, multiplicity two
   results->root1 = solve1Root(results->a, results->b );
   results->rootCount = 1;
 
   return 0;
  }

  else{
   double* roots = solve2Roots(results->a, results->b, d);
   results->root1 = roots[0];
   results->root2 = roots[1];
   results->rootCount = 2;
  }
 
 return 0;
}

double getDeterminant(qsStruct *inputs) {
    double d = inputs->b * inputs->b - 4 * inputs->a * inputs->c;
    return d;
}

double solve1Root(double a, double b) {
  double root1 = -b /(2* a);
  return root1;
}

double* solve2Roots(double a, double b, double det) {
  double root1, root2;
  static double roots[2];

  root1 = ( -b + sqrt(det)) / (2* a);
  root2 = ( -b - sqrt(det)) / (2* a);

  roots[0] = root1;
  roots[1] = root2;
  return roots;
}