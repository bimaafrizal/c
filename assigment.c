#include <stdio.h>

int main(int argc, char const *argv[])
{
    int student = 1;
    int result = 0;
    int passes  = 0;
    int failures  = 0;
    while (student <= 10)
    {
        printf("Enter result: (1=pass, 2=fail):");
        scanf("%d", &result);
        if (result == 1)
        {
            passes ++;
            student++;
        }
        else if (result == 2)
        {
            failures++;
            student++;
        }
        else
        {
            printf("Invalid input\n");
        }
    }
    printf("Passed: %d\n", passes );
    printf("Failed: %d\n", failures);
    if (passes > 8)
    {
        printf("Bonus to instructor\n");
    }

    return 0;
}
