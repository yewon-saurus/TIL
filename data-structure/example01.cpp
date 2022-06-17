#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
    char word[10];
    word[0] = 'h';
    word[1] = 'e';
    word[2] = 'l';
    word[3] = 'l';
    word[4] = 'o';
    word[5] = '\0';

    printf("%s\n", word);

    // =====

    char *words[100];
    int n = 0; // number of strings
    char buffer[BUFFER_SIZE];
    while (scanf("%s", buffer) != EOF) { // scanf("%d", a);
        words[n] = strdup(buffer);
        n++;
    }

    for (int i = 0; i < 4; i++) {
        printf("%s\n", words[i]);
    }
}