#include <stdio.h>
#include <string.h>
#define MAX_TRIES 3
void printWord(char word[], int guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char word[] = "hangman";
    int length = strlen(word);
    int guessed[length];

    for (int i = 0; i < length; i++) {
        guessed[i] = 0;
    }

    int attempts = 0;
    char guess;

    printf("Welcome to Hangman!\nYou have %d chances to guess the word.\n", MAX_TRIES);

    while (attempts < MAX_TRIES) {
        printf("\nCurrent word: ");
        printWord(word, guessed, length);

        printf("Enter your guess: ");
        scanf(" %c", &guess); 

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (found) {
            printf("Good guess!\n");
        } else {
            printf("Incorrect guess.\n");
            attempts++;
        }

        int allGuessed = 1;
        for (int i = 0; i < length; i++) {
            if (!guessed[i]) {
                allGuessed = 0;
                break;
            }
        }

        if (allGuessed) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (attempts == MAX_TRIES) {
        printf("Sorry, you've been hanged! The word was: %s\n", word);
    }
    
    return 0;
}
