#include <stdio.h>

int main(int argc, char const *argv[])
{
    // fgets -> digunakan untuk mengambil karakter dari file
    // return -> jika berhasil mengambil karakter dari file maka akan mengembalikan nilai karakter yang diambil, jika tidak maka akan mengembalikan nilai EOF
    // FILE *file;
    // int c;
    // int n = 0;
    // file = fopen("./file.txt", "r");
    // if (file == NULL)
    // {
    //     perror("Error opening file");
    //     return 1;
    // }
    // else
    // {
    //     printf("File opened successfully\n");
    //     do
    //     {
    //         c = fgetc(file);
    //         n++;
    //         printf("%c", c);

    //     } while (c != EOF);

    //     fclose(file);
    // }
    // printf("\nNumber of '$' characters: %d\n", n);
    // getchar();

    // fputs
    // digunakan untuk menulis karakter ke dalam file diakhiri dengan karakter null
    // return jika berhasil akan mengembaliukan nilai bilangan positif, jika tidak akan mengembalikan nilai EOF
    FILE *file;
    char sentence[256];
    printf("Enter a sentence: ");
    fgets(sentence, 256, stdin);
    file = fopen("./file.txt", "a");
    fputs(sentence, file);
    fclose(file);
    getchar();

    // menampilkan namun hanya sampai new line saja
    // FILE *pfile;
    // char sentence2[256];
    // pfile = fopen("./file.txt", "r");
    // if (pfile == NULL)
    // {
    //     perror("Error");
    // }
    // else
    // {
    //     if (fgets(sentence2, 100, pfile) != NULL)
    //     {
    //         puts(sentence2);
    //     }
    //     fclose(pfile);
    // }
    // getchar();

    //fprint
    //digunakan untuk menulis data berformat kedalam file stream
    FILE *pfile;
    char temp[200];
    pfile = fopen("file.txt", "r");
    if(!pfile) {
        perror("File not found");
        getchar();
        return 1;
    }
    while (!feof(pfile))
    {
        fscanf(pfile, "%s", temp);
        printf("Hasil baca: %s\n", temp);
    }
    fclose(pfile); 
    
    return 0;
}
