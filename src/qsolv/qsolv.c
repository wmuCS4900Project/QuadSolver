#include <stdio.h>
#include <math.h>
#include "../quadsolver.h"
 
qsStruct qsolve(double a, double b, double c)
{
  double d,root1,root2; 

  qsStruct results;

  results.a = a;
  results.b = b;
  results.c = c;

  d = getDeterminant(results);
     
  if(d < 0){
  // no real roots
    results.rootCount = 0;
   return results; 
  }
  else if(d==0){
   // One root, multiplicity two
   results.root1 = solve1Root(a, b );
   results.rootCount = 1;
 
   return results;
  }
  else{
   float* roots = solve2Roots(a, b, d);
   results.root1 = roots[0];
   results.root2 = roots[1];
   results.rootCount = 2;
  }
 
 return results;
}

double getDeterminant(qsStruct inputs) {
    double d = inputs.b * inputs.b - 4 * inputs.a * inputs.c;
    return d;
}

float solve1Root(double a, double b) {
  float root1 = -b /(2* a);

  return root1;
}

float* solve2Roots(double a, double b, double det) {
  float root1, root2;
  static float roots[2];

  root1 = ( -b + sqrt(det)) / (2* a);
  root2 = ( -b - sqrt(det)) / (2* a);

  roots[0] = root1;
  roots[1] = root2;
  return roots;
}