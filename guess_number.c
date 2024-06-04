#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    bool correct = false;
    srand(time(NULL));

    int number = rand() % 1000 + 1;

    printf("Welcome to the number guessing game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Please enter your guess: ");
    while (!correct)
    {
        int guess;
        scanf("%d", &guess);
        if (guess == number)
        {
            printf("Wow! You nailed it! \n");
            printf("Would you like to play again? \n");
            printf("Please type (1=yes, 2=no)?");
            int playAgain;
            scanf("%d", &playAgain);
            if (playAgain == 2)
            {
                correct = true;
                printf("Thank you for playing the number guessing game!\n");
            }
            else
            {
                printf("Welcome to the number guessing game!\n");
                printf("I have chosen a number between 1 and 100.\n");
                printf("Please enter your guess: ");
                number = rand() % 1000 + 1;
            }
        }
        else if (guess < number)
        {
            printf("Too low! Try again.\n");
            printf("Please enter your guess: ");
        }
        else
        {
            printf("Too high! Try again.\n");
            printf("Please enter your guess: ");
        }
    }

    return 0;
}