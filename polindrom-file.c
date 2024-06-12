 #include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    //read file
    char *fileName = "palindrome.txt";
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    char input[1000] = "";
    while (fgets(input, 1000, file) != NULL)
    {
        int length = strlen(input);
        //menghapus karakter newline
        if (length > 0 && input[length - 1] == '\n')
        {
            input[length - 1] = '\0';
        }
        bool isPalindrome = true;
        
        for (int i = 0; i < length / 2; i++)
        {
            if (tolower(input[i]) != tolower(input[length - i - 2]))
            {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome)
        {
            printf("The word %s is a palindrome.\n", input);
        }
        else
        {
            printf("The word %s is not a palindrome.\n", input);
        }
    }
    
    //menutup file
    fclose(file);
    return 0;
}
