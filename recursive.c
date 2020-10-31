//Example of recursive call of a function

#include <stdio.h>

void main()
{
    int number;
    long int fact(int number);
    printf("enter number\n");
    scanf("%d", &number);
    printf("Factorial of number is %ld\n", fact(number));
}

long int fact(number) 
{
    if(number <= 1)
        return(1);
    else
        return(number*fact(number-1));
}