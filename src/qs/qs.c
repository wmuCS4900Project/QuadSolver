/* This program will read floats from command line inputs or read from a file
in order to solve the quadratic equation. Inputs are taken in float form and 
calculated using double precesion to IEEE standard.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//function definitions
int takeInputs();
int runFile();
char *remove_newline(char *s);

int 
main(int argc, char * argv[])
{
	//Inputs from command line
	if(argc < 2)
      {//Start loop here instead of in takeInput
		if(takeInputs() == 0) return 0;
        
		else return -1;
	  }
    //Inputs from file
	else if(argc == 2)
      {
		char * f = argv[1];
		if(runFile(f) == 0) return 0; 
		else return -1;
	  }
    //Input error
	else
      {
        printf("Incorrect number of inputs. Please read readme for useage.\n");
	  }
	
	return -2; //shouldn't reach this point
}

/*
 takeInputs function is called in main. It gains input from 
 the command lineutilizing a char array and fgets. This is 
 how we get A, B, and C. These floats will then be validated 
 by an outside function. Once validated the float will be 
 send to qsolv.
 */
int 
takeInputs()
{
	char s[100];
	char * p = s;
	float a;
	float b;
	float c;

	for(;;)
      {

		printf("Enter your floats for the quadratic equation: \n");
		printf("A: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		a = atof(p);

		printf("B: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		b = atof(p);

		printf("C: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		c = atof(p);

		printf("found %5.5f %5.5f %5.5f \n",a,b,c);
        //call validate(? may be moved to main)
		//call qsolv(? may be moved to main)

	  }
	return 0;
}


int 
runFile(char * fname)
{
	FILE * fp;
    
	if(!(fp = fopen(fname,"r"))) return -1;
	
	char * token;
	float a, b, c;
	char readin[256];

	while(fgets(readin,sizeof(readin),fp))
    {
		token = strtok(readin," ");
		a = atof(token);
		token = strtok(NULL," ");
		b = atof(token);
		token = strtok(NULL," ");
		c = atof(token);

		printf("found %5.5f %5.5f %5.5f \n",a,b,c);
        //call validate(? may be moved to main)
        //call qsolv(? may be moved to main)
	}

	fclose(fp);

	return 0;

}

char *
remove_newline(char *s)
{
    int len = strlen(s);

    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
            // if there's a newline, truncate the string

    return s;
}
