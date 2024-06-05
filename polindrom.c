#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char input[1000] = "";

    printf("Enter a word: ");
    gets(input);
    int length = strlen(input);
    bool isPalindrome = true;
    for (int i = 0; i < length / 2; i++)
    {
        if (tolower(input[i]) != tolower(input[length - i - 1]))
        {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
    {
        printf("The word is a palindrome.\n");
    }
    else
    {
        printf("The word is not a palindrome.\n");
    }
    return 0;
}
