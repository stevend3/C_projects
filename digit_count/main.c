// Created by Steven Diniz

#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize variables
    int n = 0;
    int d = 0;
    int sum = 0;

    // get a number from the user
    printf("Enter a number: ");
    fflush(stdout);
    scanf("%d", &n);

    // get a digit from the user
    printf("Enter a digit: ");
    fflush(stdout);
    scanf("%d", &d);

    // count occurances of digit in number
    // make a duplicate of n to preserve original
    int n_dup = abs(n);

    // special condition
    if (n_dup == 0 && d == 0) {
        sum++;
    }
    // repeat until all digits have been checked
    while (n_dup > 0) {
        // get the value of the rightmost digit
        int m = n_dup % 10;
        // count times value = digit
        if (m == d) {
            sum++;
        }
        // move to the next number
        n_dup = n_dup / 10;
    }

    printf("The digit %d appears %d times in %d.\n", d, sum, n);

    return 0;
}
