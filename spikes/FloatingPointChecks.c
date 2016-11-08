//
//  FloatingPointChecks.c
//  
//
//  Created by Matthew Mazzarella on 10/18/16.
//
//
#include <math.h>
#include <stdbool.h>
#include <stdio.h>


bool abosluteCheck(float expectednum, float result);
bool relativeCheck(float expectednum, float result);

int main(int argc, char*argv[])
{
    //Initializing some test floats
    float expectednum = 12900;
    float result = 12900.00173;
    
    //absoluteCheck will return true or false
    bool answer = abosluteCheck(expectednum, result);
    
    //Prints 1 for true (within the threshold) or
    //0 for false (not within threshold)
    printf("Absolute: %d\n", answer);//DEBUG
    
    //Creating some test floats for my relative check
    float num1 = 1401.000040;
    float num2 = 1400.0000399;
    
    //relativeCheck will return true of false
    answer = relativeCheck(num1, num2);
    
    //Prints 1 for true (within the threshold) or
    //0 for false (not within threshold)
    printf("Relative: %d\n", answer);//DEBUG
}

bool abosluteCheck(float expectednum, float result)
{
    //Calculates the absolute value of the result minus
    //the expected result. Compares this to a threshold.
    float maxthreshold = .001;
    printf("%f\n", fabs(result - expectednum));//DEBUG
    if(fabs(result - expectednum) < maxthreshold)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool relativeCheck(float num1, float num2)
{
    //Relative error is measured by comparing the error to the expected result/threshold. (More accurate)
    //First we need a maximum error threshold
    float maxthreshold = .00001;
    
    //Let's see if the error is within the threshold
    printf("%f\n",fabs((num1-num2)/num2));//DEBUG
    if((fabs((num1-num2)/num2)) <= maxthreshold)
    {
        return true;
    }
    return false;
}
//single/double percision
//square root function
//
