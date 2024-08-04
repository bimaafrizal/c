#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
	char kodeBuku[3];
	char namaBuku[255];
	char jenisBuku[255];
	double hargaBuku;
}Buku;

typedef struct{
	char kodeTransaksi[3];
	char kodeBuku[3];
	int banyakBuku;
	double hargaBuku;
	double totHarga;
}Transaksi;

void InputBuku(int currBuku){
	Buku data;

	char chBuku = 'B';
	char kode[3];
	sprintf(kode, "%c%d", chBuku, currBuku);

	FILE *f_buku;

	if((f_buku=fopen("databuku.txt","ab+"))==NULL){
		printf("File tidak dapat dibuka\n");
		exit(1);
	}

	fflush(stdin);
    printf("=====Input Buku=====\n");

    printf("Nama Buku: ");
    if (fgets(data.namaBuku, sizeof(data.namaBuku), stdin) != NULL) {
        size_t len = strlen(data.namaBuku);
        if (len > 0 && data.namaBuku[len - 1] == '\n') {
            data.namaBuku[len - 1] = '\0';
        }
    }

    printf("Jenis Buku: ");
    if (fgets(data.jenisBuku, sizeof(data.jenisBuku), stdin) != NULL) {
        size_t len = strlen(data.jenisBuku);
        if (len > 0 && data.jenisBuku[len - 1] == '\n') {
            data.jenisBuku[len - 1] = '\0';
        }
    }
	printf("Harga Buku: Rp");
	scanf("%lf",&data.hargaBuku);
	fflush(stdin);
	fprintf(f_buku, "%s\t%s\t%s\t%.2lf\n", kode, data.namaBuku, data.jenisBuku, data.hargaBuku);
    printf("\nData Buku Berhasil diinput!\n");
		
	fclose(f_buku);
}

void ViewBuku(){
	Buku data;
	FILE *f_buku;
	char buffer[1024];

	if ((f_buku=fopen("databuku.txt", "rb"))==NULL){
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}

	printf("\n=============================List Buku=============================\n");
	printf("Kode Buku\tNama Buku\tJenis Buku\tHarga Buku\n");
	while (fgets(buffer, sizeof(buffer), f_buku) != NULL) {
        sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%lf", data.kodeBuku, data.namaBuku, data.jenisBuku, &data.hargaBuku);
        printf("%s\t\t%s\t\t%s\t\t%.2lf\n", data.kodeBuku, data.namaBuku, data.jenisBuku, data.hargaBuku);
    }
	fclose(f_buku);
}

void DeleteBuku() {
    char kode[10];
    Buku data;
    FILE *f_buku, *f_temp;
    char buffer[1024];

	ViewBuku();
	printf("\n===================================================================\n");

    printf("Masukkan kode buku yang akan dihapus: ");
    scanf("%s", kode);

    if ((f_buku = fopen("databuku.txt", "rb")) == NULL) {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }

    if ((f_temp = fopen("temp.txt", "wb")) == NULL) {
        printf("File sementara tidak dapat dibuat\n");
        fclose(f_buku);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), f_buku) != NULL) {
        sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%lf", data.kodeBuku, data.namaBuku, data.jenisBuku, &data.hargaBuku);
        if (strcmp(data.kodeBuku, kode) != 0) {
            fprintf(f_temp, "%s\t%s\t%s\t%.2lf\n", data.kodeBuku, data.namaBuku, data.jenisBuku, data.hargaBuku);
        }
    }

    fclose(f_buku);
    fclose(f_temp);

    remove("databuku.txt");
    rename("temp.txt", "databuku.txt");

    printf("\nData buku dengan kode '%s' telah dihapus!\n", kode);
}

void InputTransaksi(int currTran){
	Buku data;
	Transaksi dataTran;
	FILE *f_buku;
	FILE *f_transaksi;
	char buffer[1024];

	int ketemu = 0;

	char chTran = 'T';
	char kode[3];
	sprintf(kode, "%c%d", chTran, currTran);

	ViewBuku();
	printf("\n===================================================================\n");

	printf("Masukkan kode buku yang dibeli: ");
    scanf("%s", dataTran.kodeBuku);

	if ((f_buku = fopen("databuku.txt", "rb")) == NULL) {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }

	while (fgets(buffer, sizeof(buffer), f_buku) != NULL) {
        sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%lf", data.kodeBuku, data.namaBuku, data.jenisBuku, &data.hargaBuku);
        if (strcmp(data.kodeBuku, dataTran.kodeBuku) == 0) {
            dataTran.hargaBuku = data.hargaBuku;
			ketemu = 1;
        }
    }

	if(ketemu == 0){
		printf("Buku dengan kode %s tidak ada!\n",dataTran.kodeBuku);
		exit(1);
	}else{
		printf("Harga Satuan Buku: Rp %.2lf\n",dataTran.hargaBuku);
	}

	printf("Masukkan jumlah buku yang dibeli: ");
    scanf("%d", &dataTran.banyakBuku);

	dataTran.totHarga = dataTran.banyakBuku * dataTran.hargaBuku;
	printf("Total Harga: Rp %.2lf\n",dataTran.totHarga);

	if((f_transaksi=fopen("dataTransaksi.txt","ab+"))==NULL){
		printf("File tidak dapat dibuka\n");
		exit(1);
	}

	fprintf(f_transaksi, "%s\t%s\t%d\t%.2lf\t%.2lf\n", kode, dataTran.kodeBuku, dataTran.banyakBuku, dataTran.hargaBuku, dataTran.totHarga);
    printf("\nData Buku Berhasil diinput!\n");
		
	fclose(f_transaksi);
	fclose(f_buku);
}

void ViewTransaksi(){
	Transaksi data;
	FILE *f_transaksi;
	char buffer[1024];

	if ((f_transaksi=fopen("dataTransaksi.txt", "rb"))==NULL){
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}

	printf("\n=============================List Transaksi=============================\n");
	printf("Kode Transaksi\tKode Buku\tBanyak Buku\tHarga Buku\tTotal Harga\n");
	while (fgets(buffer, sizeof(buffer), f_transaksi) != NULL) {
        sscanf(buffer, "%s\t%s\t%d\t%lf\t%lf", data.kodeTransaksi,data.kodeBuku, &data.banyakBuku, &data.hargaBuku, &data.totHarga);
        printf("%s\t\t%s\t\t%d\t\t%.2lf\t%.2lf\n", data.kodeTransaksi,data.kodeBuku, data.banyakBuku, data.hargaBuku, data.totHarga);
    }
	fclose(f_transaksi);
}

void DeleteTransaksi() {
    char kode[10];
    Transaksi data;
    FILE *f_transaksi, *f_temp;
    char buffer[1024];

    ViewTransaksi();
    printf("\n===================================================================\n");

    printf("Masukkan kode transaksi yang akan dihapus: ");
    scanf("%s", kode);

    if ((f_transaksi = fopen("dataTransaksi.txt", "rb")) == NULL)
    {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }

    if ((f_temp = fopen("temp.txt", "wb")) == NULL)
    {
        printf("File sementara tidak dapat dibuat\n");
        fclose(f_transaksi);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), f_transaksi) != NULL)
    {
        if (sscanf(buffer, "%s\t%s\t%d\t%lf\t%lf", data.kodeTransaksi, data.kodeBuku, &data.banyakBuku, &data.hargaBuku, &data.totHarga) == 5)
        {
            if (strcmp(data.kodeTransaksi, kode) != 0)
            {
                fprintf(f_temp, "%s\t%s\t%d\t%.2lf\t%.2lf\n", data.kodeTransaksi, data.kodeBuku, data.banyakBuku, data.hargaBuku, data.totHarga);
            }
        }
    }

    fclose(f_transaksi);
    fclose(f_temp);

    if (remove("dataTransaksi.txt") != 0)
    {
        printf("File asli tidak dapat dihapus\n");
        exit(1);
    }

    if (rename("temp.txt", "dataTransaksi.txt") != 0)
    {
        printf("File sementara tidak dapat diubah namanya\n");
        exit(1);
    }

    printf("\nTransaksi dengan kode '%s' telah dihapus!\n", kode);
}

int main(){
	int choice;
	int bukuCount = 1;
	int transaksiCount = 1;
    char lastCode[3];
    Buku buku;

    //hitung jumlah buku
    FILE *f_buku;
    char buffer[1024];
    if ((f_buku = fopen("databuku.txt", "rb")) == NULL) {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }
    //get last code book
    while (fgets(buffer, sizeof(buffer), f_buku) != NULL) {
        sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%lf", &buku.kodeBuku, &buku.namaBuku, &buku.jenisBuku, &buku.hargaBuku);
    }
    fclose(f_buku);
    if(strlen(buku.kodeBuku) > 0){
        sscanf(buku.kodeBuku, "B%s", &lastCode);
        bukuCount = atoi(lastCode) + 1;
    }

    //hitung jumlah transaksi
    FILE *f_transaksi;
    char bufferTransaksi[1024];
    if ((f_transaksi = fopen("dataTransaksi.txt", "rb")) == NULL) {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }
    //get last code book
    while (fgets(bufferTransaksi, sizeof(bufferTransaksi), f_transaksi) != NULL) {
        sscanf(bufferTransaksi, "%s\t%s\t%d\t%lf\t%lf", &buku.kodeBuku, &buku.namaBuku, &buku.jenisBuku, &buku.hargaBuku);
    }
    fclose(f_transaksi);
    if(strlen(buku.kodeBuku) > 0){
        sscanf(buku.kodeBuku, "T%s", &lastCode);
        transaksiCount = atoi(lastCode) + 1;
    }

	do{
		system("cls");
        printf("\n\n========================Transaksi Toko Buku ABC========================\n");
		printf("1. Input Buku\n");
		printf("2. Input Transaksi\n");
        printf("3. View History Transaksi\n");
        printf("4. View Buku\n");
        printf("5. Delete History Transaksi\n");
        printf("6. Delete Buku\n");
        printf("7. Exit\n");
		printf("=======================================================================\n");
        printf("Pilih Aksi: ");
        scanf("%d",&choice);

		switch(choice){
            case 1:{
				InputBuku(bukuCount);
				bukuCount++;
                getch();
                break;
            }
            case 2:{
				InputTransaksi(transaksiCount);
				transaksiCount++;
                getch();
                break;
            }
            case 3:{
				ViewTransaksi();
				getch();
                break;
            }
            case 4:{
				ViewBuku();
				getch();
                break;
            }
            case 5:{
				DeleteTransaksi();
				getch();
                break;
            }
            case 6:{
				DeleteBuku();
				getch();
                break;
            }
            case 7:{
                printf("\nSelesai");
                getch();
                exit(0);
                break;
            }
            default:{
                printf("\nHanya ada 7 opsi");
                getch();
                break;
            }
        }
	}while(choice!=8);
}