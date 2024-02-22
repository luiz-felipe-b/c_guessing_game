#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // prints the game header
    printf("o=================================o\n");
    printf("||     Welcome to our number     ||\n");
    printf("||         guessing game!        ||\n");
    printf("o=================================o\n");

    // starting variables
    srand(time(0));
    int secretnum = rand() % 100;
    int guess;
    int correct = 0;
    int higher;
    int lower;
    int trycounter = 0;
    int usermistake = 0;
    double score = 1000;

    char boundary[] = "o=================================o\n";

    // game loop
    while (correct == 0) {
        usermistake = 0;
        trycounter++;
        printf("|| Guess %d\n", trycounter);
        printf("|| What is your guess? ");
        scanf("%d", &guess);
        printf("|| Your guess was %d.\n", guess);

        // checking for invalid inputs
        if (guess < 0) {
            printf("|| Your guess can't be negative.\n", guess);
            printf(boundary);
            trycounter--;
            usermistake = 1;
        }

        // deciding if the player got it right
        if(usermistake == 0) {
            correct = (guess == secretnum);
            if(correct) {
                printf(boundary);
                printf("|| Congrats! You got it right!\n");
                if (trycounter > 1) {
                    printf("|| It took you %d guesses in total!\n", trycounter);
                } else {
                    printf("|| What? It took you one guess?\n");
                    printf("|| You are a legend!\n");
                }
                printf("|| Final score: %.1f\n", score);
            } else {
                printf(boundary);
                printf("|| Unfortunately you got it wrong...\n");
                higher = (guess > secretnum);
                if(higher) {
                    printf("|| The secret number is actually lower.\n");
                } 
                else {
                    printf("|| The secret number is actually higher.\n");   
                }
                double lostscore = abs(guess - secretnum) / (double)2;
                score = score - lostscore; 
            }
                printf(boundary);
        }
    }
}