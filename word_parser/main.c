// Read strings from a file.  Find longest, shortest, first, and last strings.
// Steven Diniz

#include <stdio.h>
#include <string.h>
#include <ctype.h>   // ispunct

int wordInfo(const char* fname, char *shortest, char *longest, char *lowest, char *highest);

int main() {
    char filename[25];
    char shortWord[16] = "";
    char longWord[16] = "";
    char firstWord[16] = "";
    char lastWord[16] = "";
    printf("Filename: ");
    fflush(stdout);
    scanf("%24s", filename);

    int w = wordInfo(filename, shortWord, longWord, firstWord, lastWord);
    if (w < 0) {
        printf("Unable to open file: %s\n", filename);
        return 0;
    }
    printf("File has %d words.\n", w);
    printf("Shortest word: %s\n", shortWord);
    printf("Longest word: %s\n", longWord);
    printf("Alphabetically first: %s\n", firstWord);
    printf("Alphabetically last: %s\n", lastWord);
    
    return 0;
}

int wordInfo(const char *fname, char *shortest, char *longest, char *lowest, char *highest) {
    int num_words = 0;
    int word_len = 0;
    int long_len = 0;
    int short_len = 16;

    char word[16] = {0};
    char *start_long = longest;
    char *start_short = shortest;
    char *start_lowest = lowest;
    char *start_highest = highest;

    // initialize lowest
    *start_lowest = '~';

    FILE *file = fopen(fname, "r");
    // ensure file was found and opened
    if (!file) return -1;

    // scan through file
    while (fscanf(file, "%s", word) != EOF) {
        // count # of words in file
        num_words++;

        // get length of word
        word_len = 0;
        word_len = strlen(word);
        // don't count punctuation at the end
        if (!isalnum(word[word_len - 1])) word[word_len - 1] = '\0';

        // longest word
        if (word_len > long_len) {
            // reset pointer to longest word
            longest = start_long;

            // update len of longest word
            long_len = word_len;

            // store the word in longest without punctuation
            strcpy(longest, word);
        }

        // shortest word
        if (word_len < short_len && word_len > 0) {
            // reset pointer to shortest word
            shortest = start_short;

            // update shortest word len;
            short_len = word_len;

            // remove previous word
            while (*shortest) *shortest++ = '\0';
            shortest = start_short;

            // store word in shortest without punctuation
            strcpy(shortest, word);
        }

        // first alphabetically
        if (strcasecmp(word, start_lowest) < 0) {
            // reset start of lowest
            lowest = start_lowest;

            // clear lowest
            while(*lowest) *lowest++ = '\0';
            lowest = start_lowest;

            // store word in lowest without punctuation
            strcpy(lowest, word);
        }
        // last alphabetically
        if (strcasecmp(word, start_highest) > 0) {
            // reset start of highest
            highest = start_highest;

            // clear whatever is in highest
            while (*highest) *highest++ = '\0';
            highest = start_highest;

            // store word in highest without punctuation
            strcpy(highest, word);
        }

        // reset word to NULL
        for (int i = 0; i < 16; i++) word[i] = '\0';
    }
    fclose(file);

    return num_words;
}