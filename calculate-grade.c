#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STUDENT 10

char calculateGrade(float finalGrade)
{
    if (finalGrade <= 55)
    {
        return 'E';
    }
    else if (finalGrade <= 65)
    {
        return 'D';
    }
    else if (finalGrade <= 75)
    {
        return 'C';
    }
    else if (finalGrade <= 85)
    {
        return 'B';
    }
    else
    {
        return 'A';
    }
}

void printResult(char **studentName, float *nilai_quis, float *nilai_tugas, float *nilai_absensi, float *nilai_praktek, float *nilai_uas, float *average, int j)
{
    char grade = calculateGrade(average[j]);
    char *lulus = average[j] >= 65 ? "Lulus" : "Tidak Lulus";
    printf("Nama: %s\n", studentName[j]);
    printf("Nilai Quis: %.2f\n", nilai_quis[j]);
    printf("Nilai Tugas: %.2f\n", nilai_tugas[j]);
    printf("Nilai Absensi: %.2f\n", nilai_absensi[j]);
    printf("Nilai Praktek: %.2f\n", nilai_praktek[j]);
    printf("Nilai UAS: %.2f\n", nilai_uas[j]);
    printf("Nilai Rata-rata: %.2f\n", average[j]);
    printf("Grade: %c\n", grade);
    printf("Status: %s\n", lulus);
}

float inputNilai(char *message)
{
    float nilai;
    do {
        printf("%s", message);
        scanf("%f", &nilai);
        if (nilai < 0 || nilai > 100) {
            printf("Nilai tidak valid! Masukkan nilai antara 0 dan 100.\n");
        }
    } while (nilai < 0 || nilai > 100);

    return nilai;
}

int main()
{
    int i = 0;
    int currentStudent = INITIAL_STUDENT;
    bool status = true;

    char **studentName = (char **)malloc(currentStudent * sizeof(char *));
    float *nilai_quis = (float *)malloc(currentStudent * sizeof(float));
    float *nilai_tugas = (float *)malloc(currentStudent * sizeof(float));
    float *nilai_absensi = (float *)malloc(currentStudent * sizeof(float));
    float *nilai_praktek = (float *)malloc(currentStudent * sizeof(float));
    float *nilai_uas = (float *)malloc(currentStudent * sizeof(float));
    float *average = (float *)malloc(currentStudent * sizeof(float));

    int statusInput;

    do
    {
        if (i >= currentStudent)
        {
            currentStudent += 10; // Tambah ukuran memori
            studentName = (char **)realloc(studentName, currentStudent * sizeof(char *));
            nilai_quis = (float *)realloc(nilai_quis, currentStudent * sizeof(float));
            nilai_tugas = (float *)realloc(nilai_tugas, currentStudent * sizeof(float));
            nilai_absensi = (float *)realloc(nilai_absensi, currentStudent * sizeof(float));
            nilai_praktek = (float *)realloc(nilai_praktek, currentStudent * sizeof(float));
            nilai_uas = (float *)realloc(nilai_uas, currentStudent * sizeof(float));
            average = (float *)realloc(average, currentStudent * sizeof(float));;
        }

        printf("Masukkan nilai untuk mahasiswa ke-%d\n", i + 1);
        float quis, tugas, absensi, praktek, uas;
        char *name = (char *)malloc(100 * sizeof(char));

        printf("Nama: ");
        scanf("%s", name);
        studentName[i] = name;
        
        nilai_quis[i] = inputNilai("Nilai Quis: ");
        nilai_tugas[i] = inputNilai("Nilai Tugas: ");
        nilai_absensi[i] = inputNilai("Nilai Absensi: ");
        nilai_praktek[i] = inputNilai("Nilai Praktek: ");
        nilai_uas[i] = inputNilai("Nilai UAS: ");

        // Perhitungan nilai rata-rata
        average[i] = (nilai_quis[i] + nilai_tugas[i]  + nilai_absensi[i] + nilai_praktek[i] + nilai_uas[i]) / 5;

        printf("\nApakah anda ingin menambahkan nilai lagi? (1 = ya, 2 = tidak): ");
        scanf("%d", &statusInput);

        if (statusInput == 2)
        {
            if (i < 5)
            { 
                printf("Jumlah mahasiswa kurang dari 10, tambahkan lagi\n");
                i++;
                continue;
            }

            printf("\nHasil Penilaian Mahasiswa:\n");
            for (int j = 0; j <= i; j++)
            {
                printResult(studentName, nilai_quis, nilai_tugas, nilai_absensi, nilai_praktek, nilai_uas, average, j);
            }

            status = false;
            return 0;
        }
        else if (statusInput == 1)
        {
            i++;
        }
        else
        {
            goto error;
        }

    } while (status);

    error:
        printf("Wrong input!\n");
        return 1;

    return 0;
}