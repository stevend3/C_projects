/* Caesar cipher - offset letters and digits by specified key (character)
 *
 * Usage: Upon running the file, select to encrypt or decrypt, select a key,
 * and type your message ending with ##.
 * The program will either encrypt or decrypt your message based on the key
 * and will print the output below.
 *
 * Steven Diniz 9/5/2020
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    // encrypt or decrypt
    char mode = 0;
    // how to encrypt or decrypt
    int key = -1;

    // Get information from user -- encrypt/decrypt mode
    // ensure they enter either e or d
    do {
        printf("Enter mode -- encrypt (e) or decrypt (d): ");
        scanf(" %c", &mode);
        if (isupper(mode) != 0) mode = toupper(mode);
    } while ((mode != 'd') && (mode != 'e'));

    // get the key from user
    while ((key < 0) || (key > 35)) {
        printf("Enter key (0-35): ");
        fflush(stdout);
        scanf("%d", &key);
    }
    scanf("%*c");  // read and ignore linefeed after key
    printf("Enter text, ending with ##:\n");
    fflush(stdout);

    // Read input one character at a time
    // Encrypt or decrypt, according to mode
    // Print as described in program spec

    // define 'alphabet' for the problem
    char index[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U',
                     'V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    // where the letter is in the alphabet
    int index_pos = -1;
    int stop = 0;
    char letter;
    int word_len = 0;
    int groups = 0;

    // run until user enters 2 #'s
    while (stop < 2) {
        // get letter
        scanf("%c", &letter);

        // check for #
        if (letter == '#') stop++;
        // check for letter or number
        else if (isalnum(letter) != 0) {
            // ensure letters are uppercase
            if (isdigit(letter) == 0) letter = toupper(letter);

            // scan through alphabet to find index_pos
            for (int i = 0; i < 36; i++) {
                if (letter == index[i]) {
                    index_pos = i;
                }
            }

            // encryption with wrap around
            if (mode == 'e') index_pos = (index_pos + key) % 36;

            // decryption
            else if (mode == 'd') {
                // decrypt key
                index_pos -= key;

                // enable wrap around
                if (index_pos < 0) index_pos += 36;

            }

            // convert to ascii
            letter = index[index_pos];

            // properly format output
            // group output into 4 letters
            if (word_len == 4) {
                groups++;
                word_len = 0;
                // only include 5 groups on each line
                if (groups != 5) printf(" ");
                else {
                    printf("\n");
                    groups = 0;
                }

            }

            printf("%c", letter);
            word_len++;
            // reset stop
            stop = 0;
        }

    }
    printf("\n");

    return 0;
}
