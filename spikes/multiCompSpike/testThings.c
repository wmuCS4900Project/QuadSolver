#include <stdio.h>

int main( int argc, char *argv[] )  {

   if( argc == 4 ) {
      printf("The argument supplied is %s\n", argv[1]);
	printf("The argument supplied is %s\n", argv[2]);
	printf("The argument supplied is %s\n", argv[3]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }
}
