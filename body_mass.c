#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

int main(void)
{
    float weight;
    float height;
    bool correct = false;
    float bmi;

    while (!correct)
    {
        printf("Welcome to the body mass index calculator!\n");
        getch();
        printf("Enter your weight in kg: ");
        scanf("%f", &weight);
        printf("Enter your height in cm: ");
        scanf("%f", &height);
        // convert cm to m
        height = height / 100;
        bmi = weight / (height * height);
        printf("Your BMI is: %.2f\n", bmi);

        if (bmi < 18.5)
        {
            printf("You are underweight.\n");
        }
        else if (bmi >= 18.5 && bmi < 24.9)
        {
            printf("You are normal weight.\n");
        }
        else if (bmi >= 25 && bmi < 29.9)
        {
            printf("You are overweight.\n");
        }
        else
        {
            printf("You are obese.\n");
        }

        printf("Would you like to calculate again? (1=yes, 2=no): ");
        int playAgain;
        scanf("%d", &playAgain);
        if (playAgain == 2)
        {
            correct = true;
            printf("Thank you for using the body mass index calculator!\n");
        }
    }

    return 0;
}
