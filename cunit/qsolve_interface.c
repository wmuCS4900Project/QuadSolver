// qsolve_interface.c
// The main and io for qsolve.
// This should likely be broked done into seperate modules viz 
// the three level design to improve unit testing.S
//
// MY BAD. These comments really need an example and notes on how it should run,
// as the return values it provides!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsolve_roots.h"

//X NLINE is the size of the char array str and the lenght of the longest legal user input line.
#define NLINE 100

//X Line is a structure for passing a line of text, and a code for status
typedef struct {
  int   max;   // size of str array
  int   len;   // legnth of string in str
  int   code;  // status code
  char  *str;  // pointer to array of max bytes
}  Line;

int validator_abc(Line *linein, Coef *coef);

int main() {
char	response[3];// User response: "Y" or "N"
Line	linein;     // input line from user
Coef	coef;       // coefs of the quadratic (3 doubles), passed to qsolve
Root    root;       // roots of the quadratic (2 doubles), returned from qsolve()
int	qs;         // qsolve() return code

linein.max = NLINE;
if( (linein.str = malloc(NLINE)) == NULL)  {
  fprintf(stderr,"Systems failure no memory for malloc(%d)\n", NLINE);
  exit(1); 
}
linein.len=0;
linein.code=-1;
linein.str= '\0';

printf("Quadratic Equation Solver, Ver 1.01\nFinds real roots of a quadratic equation.\n");

while(1) {
  while(1) {
    printf("Do you want to solve a quadratic eqauation ax^2 + bx + c = 0 ? (Y/N):");
    if(fgets(response, 2, stdin) == NULL) {
     fprintf(stderr,"Input error: can not read from stdin\n");
     exit(1);
    }
    if(strncmp(response, "Y", 3) ) {
      break;
    } else if(strncmp(response, "N", 3) ) {
      exit(0);
    } else {
      fprintf(stderr,"Input error: response must be a single character: Y or N\n"); 
    }
  }

  printf("Input a b c :" );
  if(fgets(linein.str, linein.max, stdin) == NULL) {
     fprintf(stderr,"Input error: can not read from stdin\n");
     exit(1);
  }
  if(validator_abc(&linein, &coef) != 0) {
    fprintf(stderr,"Input error: a b and c must be real numbers,\n  example: 1.0  2.2  4.4\n");
    continue; 
  } else {
    switch (qs=qsolve_roots(&coef, &root))  {
    case -2: // No real roots
             printf("No real roots\n");
             break;
    case -1: // Not a quadratic (a == 0)
             printf("Not a quadratic (a==0)\n");
             break;
    case 1:  // double real root
             printf("Double real root %24.16f", root.x1);
             break;
    case 2:  // two distinct roots
             printf("Roots  %24.16f  %24.16f", root.x1, root.x2);
             break;
    default: fprintf(stderr,"System failure: quadratic solver error code=%d\n", qs);
             exit(1);
             break;
    }
  }
}
exit(0);
}


// The validator could be put in a separate module for unit testing and reuse.
// It could be gerenalized to validating and extracting n doubles from a string.
int validator_abc(Line *linein, Coef *coef) {
double  a,b,c;
char    ch;

if(sscanf(linein->str,"%lf %lf %lf%c", &a, &b, &c, &ch) != 3) {
  return -1;
}
coef->a = a;
coef->b = b;
coef->c = c;
return 0;
}
