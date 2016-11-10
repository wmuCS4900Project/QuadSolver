/* This program will read floats from command line inputs or read from a file
in order to solve the quadratic equation. Inputs are taken in float form and 
calculated using double precesion to IEEE standard.*/
#include "../quadsolver.h"



int 
main(int argc, char * argv[])
{
	//Inputs from command line
	if(argc < 2)
      {//Start loop here instead of in takeInput
		if(takeInputs() == 0) return 0;
        
		else return -1;
	  }
 //    //Inputs from file
	// else if(argc == 2)
 //      {
	// 	char * f = argv[1];
	// 	if(runFile(f) == 0) return 0; 
	// 	else return -1;
	//   }
    //Input error
	else
      {
        printf("Incorrect number of inputs. Please read readme for useage.\n");
	  }
	
	return -2; //shouldn't reach this point
}