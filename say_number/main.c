/* Steven Diniz
 * Program gets a decimal number from user, then prints one digit of that number
 * as an English word, and finally prints the entire number in English.
 */
#include <stdio.h>
#include <stdlib.h>

/* Function declarations (prototypes) */
int numDigits(int);  /* number of decimal digits in an integer value */
int nthDigit(int, int);   /* value of digit N, where 0 is the one's digit */
void sayDigit(int);  /* prints the English word for a one-digit decimal number */
void sayNumber(int);  /* prints the English words for all digits of a decimal number */

int main() {
    int num = 0;  /* good idea to initialize variable, so it has a known value */
    int nDigits = 0;
    int topDigit = 0;

    printf("Enter a non-negative decimal integer: ");
    fflush(stdout);
    scanf("%d", &num);
    /* Does not check for negative number -- assumes user will follow directions */

    nDigits = numDigits(num);
    printf("The number has %d digits.\n", nDigits);
    /* Another opportunity to check for negative number (zero digits) */

    topDigit = nthDigit(num, nDigits);
    printf("The most significant digit is %d, also known as ", topDigit);
    sayDigit(topDigit);
    printf(".\n");
    sayNumber(num);
    printf("\n");
    return EXIT_SUCCESS;
}

/* numDigits: how many decimal digits in an integer value?
 * input: val = a non-negative integer
 * returns: the number of decimal digits
 * exceptions: if negative, returns 0
 */
int numDigits(int val) {
    int digits = 0;
    if (val == 0)
        digits = 1;
    else {
        while (val > 0) {
            digits += 1;  /* >0 means at least one non-zero digit */
            val /= 10;    /* decimal shift to the right */
        }
    }
    /* NOTE: Supposed to return zero if negative -- does it? */
    return digits;
}

/* nthDigit: value of nth decimal digit
 * inputs:
 *    val = a non-negative integer
 *    n = the digit of interest: 0 is the one's digit, 1 is the 10's digit, etc.
 * returns: the value of the nth digit
 * assumptions: value is >= 0, n is >= 0
 * Use integer operations only -- do NOT use pow().
 */
int nthDigit(int val, int n) {
    // isolate the most significant bit
    if (n != 0) {
        for (int i = 0; i < n - 1; i++) {
            val /= 10;
        }
    }
    // determine sig_fig
    int sig_fig = val % 10;
    return sig_fig;
}

/* sayDigit: print English version of a decimal digit
 * input: digit = a 1-digit decimal number
 * returns: nothing
 * Print in lower-case, no spaces before or after.
 * Print to stdout.
 * assumptions: 0 <= digit <= 9
 * Example: digit = 4, prints "four"
 */
void sayDigit(int digit) {
    char num_words[10][6] = {
                                "zero",
                                "one",
                                "two",
                                "three",
                                "four",
                                "five",
                                "six",
                                "seven",
                                "eight",
                                "nine"
                            };
    printf("%s", num_words[digit]);
}

/* sayNumber: print English words for all digits of a number, from high to low
 * input: n = a non-negative integer
 * returns: nothing
 * Print in lower-case, one space **after** each digit word.
 * Print to stdout.
 * assumptions: n >= 0
 * Example: n=123, prints "one two three "
 */
void sayNumber(int n) {
    /* Don't replicate code.
     * Use the numDigits, nthDigit, and sayDigit functions in your implementation.
     */
    for (int i = numDigits(n) ; i > 0; i--) {
        int digit = nthDigit(n, i);
        sayDigit(digit);
        printf(" ");
    }
}
