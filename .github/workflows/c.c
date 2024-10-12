#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    // Prompt user for input
    printf("Enter a month number (1-12): ");
    
    // Check if input is a valid integer
    if (scanf("%d", &a) != 1) {
        printf("Input is not a number.\n");
        return 1; 
    }

    // Determine the month based on user input
    switch (a) {
        case 1:
            printf("Januari\n");
            break;
        case 2:
            printf("Februari\n");
            break;
        case 3:
            printf("Maret\n");
            break;
        case 4:
            printf("April\n");
            break;
        case 5:
            printf("Mei\n");
            break;
        case 6:
            printf("Juni\n");
            break;
        case 7:
            printf("Juli\n");
            break;
        case 8:
            printf("Agustus\n");
            break;
        case 9:
            printf("September\n");
            break;
        case 10:
            printf("Oktober\n");
            break;
        case 11:
            printf("November\n");
            break;
        case 12:
            printf("Desember\n");
            break;
        default:
            printf("Invalid month number entered.\n");
    }
    return 0;
}
