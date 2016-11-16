//This is a code spike for using stdin and stdout instead of prints and file reads

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct pass
{
	int retval;
	float floats[3];
}pass;


int 
main(int argc, char * argv[])
{
	
	char * in;
	size_t insize = 500;

	in = (char *)malloc(insize * sizeof(char));

	printf("Enter three floats as a, b and c.");

	ssize_t rsize = getline(&in, &insize, stdin);

	printf("Read in %s with %zu chars\n",in,rsize);

	pass * p = (pass *)malloc(sizeof(pass));

	int retval = validator(p, in);
	printf("Retval is %d\n", retval);

	printf("Found %f %f %f \n",p->floats[0],p->floats[1],p->floats[2]);

}

int 
validator(pass * p, char * in)
{
	char * c[100];
	int a;
	for(a=0; a < 100; a++){
		c[a] = (char *)malloc(sizeof(char) * 50);
	}

	int count = 0;

	char * token;


	token = strtok(in, " ");
	while(token != NULL){
		strncpy(c[count],token,sizeof(token));
		printf("Found %s\n",c[count]);
		count++;
		token = strtok(NULL, " ");
	}

	if(count < 3) return -2; //too few args
	if(count > 3) return -3; //too many args

	float z = atof(c[0]);
	printf("Found z %f\n",z);
	p->floats[0] = atof(c[0]);
	p->floats[1] = atof(c[1]);
	p->floats[2] = atof(c[2]);

	printf("Found %f %f %f \n",p->floats[0],p->floats[1],p->floats[2]);

	return 0;
}

char *
remove_newline(char *s)
{
    int len = strlen(s);

    if (len > 0 && s[len-1] == '\n')  // if there's a newline
        s[len-1] = '\0';          // truncate the string

    return s;
}