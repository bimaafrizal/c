#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char fname[20], ch;
    FILE *fpts, *fptt;
    printf("\n\n Encrypt a text file : \n");
    printf("--------------------------\n");
    printf(" Input the name of file to encrypt : ");
    scanf("%s", fname);
    fpts = fopen(fname, "r");
    if (fpts == NULL)
    {
        printf(" File does not exists or error in opening..!!");
        exit(1);
    }

    fptt = fopen("temp.txt", "w");
    if(fptt == NULL)
    {
        printf("Error in creating temp.txt file..!!");
        fclose(fpts);
        exit(2);
    }
    
    while ((ch = fgetc(fpts)) != EOF)
    {
        ch = ch + 100;
        fputc(ch, fptt);
    }

    fclose(fpts);
    fclose(fptt);

    fptt = fopen("temp.txt", "r");
    if(fptt == NULL)
    {
        printf("Error in opening temp.txt file..!!");
        exit(3);
    }

    fpts = fopen(fname, "w");
    if(fpts == NULL)
    {
        printf("Error in opening source file..!!");
        fclose(fptt);
        exit(4);
    }
    
    while ((ch = fgetc(fptt)) != EOF)
    {
        fputc(ch, fpts);
    }

    printf("File %s encrypted successfully..!!\n", fname);

    fclose(fpts);
    fclose(fptt);
    
    return 0;
}
