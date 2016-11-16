#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int main()
{
//this program uses command to call another program and pipe the result into testTxt.txt
system("../install/./qsolver < test1.txt > output.txt");

//system("./testThings 2 1 3 >> testTxt.txt");

//then in compares the file to an answer key to see if the program run correctly
system("grep -v -F -x -f answerKey.txt output.txt");

//prints an all done after its complete
printf("Test complete.\n");

}
