#include <stdio.h>

int main() {
    int n, r, sum = 0, temp;
    printf("Enter The number:");
    scanf("%d", &n);
    temp = n;
    while (n > 0) {
        r = n % 10;
        sum = sum * 10 + r;
        n = n / 10;
    }
    if (temp == sum) {
        printf("The number is Palindrome Number\n");
    } else {
        printf("The Number is Not Palindrome\n");
    }
    return 0;
}
