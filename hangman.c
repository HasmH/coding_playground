#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_STRING_SIZE 20
int main(void){
    int player_score = 6;
    srand(time(NULL)); 
    int secret_index = rand();
    secret_index = secret_index % 10;
    char dictionary[10][MAX_STRING_SIZE] = {
        "abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom" "azure", "bagpipes" 
    };
    char *secret_word = dictionary[secret_index];
    printf("Welcome to Hangman\n");
    printf("--------------------\n"); 
    char guessed_correctly[MAX_STRING_SIZE];
    int word_length = strlen(secret_word);
    for (int i = 0; i < word_length; i++){
        guessed_correctly[i] = '_'; 
    }
    guessed_correctly[word_length] = '\0';
    printf("%s\n", guessed_correctly);
    char guess; 
    while (player_score > 0) {
        printf("Enter letter:\n");
        scanf(" %c", &guess);
        if (strchr(secret_word, guess) != NULL){
            printf("You're right!\n"); 
            for (int j = 0; j < word_length; j++) {
                if (guess == secret_word[j]) {
                    guessed_correctly[j] = guess;
                }
            }
        } 
        if (strchr(secret_word, guess) == NULL) {
            player_score--;
            printf("Wrong.. Try again. You have %d points left..\n", player_score); 
        }
        if (player_score == 0) {
            printf("Game Over! You lost all your points.\n");
            printf("The word was %s.\n", secret_word); 
            return 0; 
        } 
        if (strcmp(secret_word, guessed_correctly) == 0) {
            printf("Congratulations - you have guessed the word - %s\n", secret_word); 
            return 0;
        }
        printf("%s\n", guessed_correctly);
    }
}