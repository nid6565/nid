/******************************************************************************
 * Mid-Term    : Write C program >> Question 1
 * File Name : Q1.c
 * Data      : 19/8/2023
 * Author    : Omar Abdelrahman Elshahat
 * brief     : c function to take a number and sum all digits
 *****************************************************************************/
//----------------------------------------------------------------------------//
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ********************** Includes Section End   ********************** */
//----------------------------------------------------------------------------//

/* ********************** Functions Declaration Section Start ************* */
void sum_digits(char array[]);
/* ********************** Functions Declaration Section End ************* */
//----------------------------------------------------------------------------//
int main()
{
    char number_as_string[100]; // Local array to store user input
    printf("Enter number: ");
    scanf("%s", number_as_string);
    sum_digits(number_as_string);
    return 0;
}
/* ********************** Functions Definition Section Start ************* */
void sum_digits(char array[]){
    int Index, sum = 0;
    for (Index = 0; array[Index] != '\0'; Index++) {
        if (array[Index] >= '0' && array[Index] <= '9') {
            sum += array[Index] - '0';
        }
    }
    printf("%d", sum); // Output the final sum
}
/* ********************** Functions Definition Section End ************* */
//----------------------------------------------------------------------------//
