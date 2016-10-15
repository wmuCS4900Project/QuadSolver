#include <string.h>
#include <math.h>

double under(int a);
double inner(int a, int b, int c);
void paths(double in, double u, int b);

void main(int argc, char* argv[]){
	
	
	if(argc < 3){
		printf("Please include a, b and c\n");
		return -1;
	}
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	
	printf("Finding ax^2 + bx + c = 0\n");
	
	double u = under(a);
	if(u == 0){
		
		
		printf("u = 0\n");
		return -1;
		
	}
	else
	{
		double in = inner(a,b,c);
		if(in == -1) return -1;
		
		paths(in,u,b);
		
	}
		
	
	return 0;
	
}

double under(int a){
	double x = 2 * a;
	return x;	
}

double inner(int a, int b, int c){
	
	double x = b * b;
	double y = 4 * a * c;
	
	if(x < y){
	
		printf("X < Y\n");
		return -1;
	}
	
	double z = x - y;
	
	double t = sqrt(z);
	
	return t;	
	
}

void paths(double in, double u, int b){
	
	double x = -b + in;
	double y = x / u;
	
	double w = -b -in;
	double v = w / u;
	
	printf("Answers are %f and %f\n",y,v);
	
	
}
