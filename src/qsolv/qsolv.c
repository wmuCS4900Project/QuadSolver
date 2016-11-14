#include <stdio.h>
#include <math.h>
#include "../../quadsolver.h"
 
int main(){
  float a,b,c;
  a = 1;
  b = 2; 
  c = 1;
  float d,root1,root2; 

  qsStruct results;

  results.a = a;
  results.b = b;
  results.c = c;

  d = getDeterminant(results);
     
  if(d < 0){
    printf("Roots are complex number.\n");
 
    printf("Roots of quadratic equation are: ");
    printf("%.3f%+.3fi",-b/(2*a),sqrt(-d)/(2*a));
    printf(", %.3f%+.3fi",-b/(2*a),-sqrt(-d)/(2*a));
  
    return 0; 
  }
  else if(d==0){
   printf("Both roots are equal.\n");
 
   root1 = -b /(2* a);
   printf("Root of quadratic equation is: %.3f ",root1);
 
   return 0;
  }
  else{
   printf("Roots are real numbers.\n");
  
   root1 = ( -b + sqrt(d)) / (2* a);
   root2 = ( -b - sqrt(d)) / (2* a);
   printf("Roots of quadratic equation are: %.3f , %.3f",root1,root2);
  }
 
  return 0;
}

getDeterminant(qsStruct inputs) {
    float d = inputs.b * inputs.b - 4 * inputs.a * inputs.c;
}