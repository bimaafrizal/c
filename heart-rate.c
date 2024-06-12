#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int validateInput(char timeStr[], int *day, int *month, int *year);
int ageCount(int day, int month, int year);
void countHeartRate(int age, double *maxHeartRate, double *lowTargetRate, double *highTargetRate);

int main(int argc, char const *argv[])
{
    //get the current time
    char timeStr[100];
    int day, month, year, age;
    double maxHeartRate, lowTargetRate, highTargetRate;
    printf("Enter your birthday (08-05-2024): ");
    scanf("%s", timeStr);
    if (validateInput(timeStr, &day, &month, &year) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }
    age = ageCount(day, month, year);
    countHeartRate(age, &maxHeartRate, &lowTargetRate, &highTargetRate);
    printf("Umur Anda %d\n", age);
    printf("Detak Jantung Maksimal Anda %.2f\n", maxHeartRate);
    printf("Target detak jantung Anda %.2f\n - %.2f\n", lowTargetRate, highTargetRate);

    /* code */
    return 0;
}

int validateInput(char timeStr[], int *day, int *month, int *year)
{
    //check the length of the string
    if (strlen(timeStr) != 10)
    {
        return 0;
    }
    
    //parse day, month, and year
    if (sscanf(timeStr, "%d-%d-%d", day, month, year) != 3)
    {
        return 1; // Invalid format
    }
    
    //check year 
    if (*year < 1900 || *year > 9999)
    {
        return 0;
    }

    //check month
    if (*month < 1 || *month > 12)
    {
        return 0;
    }

    //chek day
    int maxDay = 31;
    if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
    {
        maxDay = 30;
    }
    else if (*month == 2)
    {
        if (*year % 4 == 0 && (*year % 100 != 0 || *year % 400 == 0))
        {
            maxDay = 29;
        }
        else
        {
            maxDay = 28;
        }
    }
    
    if (*day < 1 || *day > maxDay)
    {
        return 0;
    }
    
    return 1;
}

int ageCount(int day, int month, int year)
{
    //get the current time
    time_t t;
    struct tm *now;
    time(&t);
    now = localtime(&t);
    int currentDay = now->tm_mday;
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;

    //calculate the age
    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day))
    {
        age--;
    }
    return age;
}

void countHeartRate(int age, double *maxHeartRate, double *lowTargetRate, double *highTargetRate)
{
    *maxHeartRate = 220 - age;
    *lowTargetRate = 0.5 * (*maxHeartRate);
    *highTargetRate = 0.85 * (*maxHeartRate);
}
