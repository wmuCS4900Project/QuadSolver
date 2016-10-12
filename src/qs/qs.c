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
	int a, b, c;
	char readin[256];

	while(fgets(readin,sizeof(readin),fp)){
		token = strtok(readin," ");
		a = atoi(token);
		token = strtok(NULL," ");
		b = atoi(token);
		token = strtok(NULL," ");
		c = atoi(token);

		printf("found %d %d %d \n",a,b,c);

		//call qsolv
	}

	fclose(fp);
	
	return 0;
}
