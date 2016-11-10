#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*Read in inputs while there are inputs in file given in command line input */


int main(int argc, char * argv[]){
	
	if(argc < 2){
		printf("No filename included\n");
		return -1;
	}

	FILE * fp;

	if(!(fp = fopen(argv[1],"r"))) return -1;
	
	//char * readin = malloc(100);
	char * token;
	double a, b, c;
	char readin[256];
	char* end;

	while(fgets(readin,sizeof(readin),fp)){
		token = strtok(readin," ");
		a = strtod(token, &end);

		// TODO: Make this part of? 
		if(end == token) {
			// a conversion was not performed
			printf("%s Is not a valid number\n", token );
			continue;
		}

		token = strtok(NULL," ");
		b = strtod(token, &end);

		if(end == token) {
			// a conversion was not performed
			printf("%s Is not a valid number\n", token );
			continue;
		} 

		token = strtok(NULL," ");
		c = strtod(token, &end);

		if(end == token) {
			// a conversion was not performed
			printf("%s Is not a valid number\n", token );
			continue;
		}

		printf("found %lf %lf %lf \n",a,b,c);

		//call qsolv
	}

	fclose(fp);
	
	return 0;
}
