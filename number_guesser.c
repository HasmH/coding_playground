#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){

    //Get a randomnumber
    srand(time(NULL)); 
    int number = rand();
    number = number % 100 + 1;
    int input = 0;
    printf("Enter a number between 1 and 100\n");
    scanf("%d", &input); 
    while (input != EOF) {
        if (number == input) {
            printf("You guessed correctly.\n");
            return 0; 
        }
        else if (input > number) {
            printf("Too high\n");
        } else if (input < number) {
            printf("Too low\n");
        } 
        scanf("%d", &input); 
    }
}