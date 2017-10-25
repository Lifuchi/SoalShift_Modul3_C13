#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

struct stock{
int MP4A1;
int PM2_V1;
int SPR_3;
int SS2_V5;
int SPG1_V3;
int MINE;
//int status;
};

int main(){
struct stock *data;
char nama_barang[100];

key_t KEY = ftok("#", 'A');
int sharedID = shmget(KEY, sizeof(struct stock), IPC_CREAT | 0666);

//key_t KEY;
int pilih;

//char senjata[100];
int total;
data = (struct stock *) shmat(sharedID, NULL, 0);

while(1)
{
printf("1. Lihat stock senjata\n");
printf("2. Isi stock senjata\n");
scanf("%d", &pilih);

if (pilih == 1)
{
 if(data->MP4A1>0){
 printf("Jumlah MP4A1 = %d\n", data->MP4A1);
 }

 if(data->PM2_V1>0){
 printf("Jumlah PM2-V1 = %d\n", data->PM2_V1);
 }

 if(data->SPR_3>0){
 printf("Jumlah SPR-3 = %d\n", data->SPR_3);
 }

 if(data->SS2_V5>0){
 printf("Jumlah SS2-V5 = %d\n", data->SS2_V5);
 }

 if(data->SPG1_V3>0){
 printf("Jumlah SPG1-V3 = %d\n", data->SPG1_V3);
 }

 if(data->MINE>0){
 printf("Jumlah MINE = %d\n", data->MINE);
 }
else
printf("stock kosong");
}  
else if(pilih == 2){
scanf("%s %d", nama_barang, &total);

if (strcmp(nama_barang,"MP4A1")==0){
data->MP4A1 += total;
printf("Jumlah stock MP4A1 = %d \n", data->MP4A1);
}

if (strcmp(nama_barang,"PM2-V1")==0){
data->PM2_V1 += total;
printf("Jumlah stock PM2-V1 = %d \n", data->PM2_V1);
}

if (strcmp(nama_barang,"SPR-3")==0){
data->SPR_3 += total;
printf("Jumlah stock SPR-3 = %d \n", data->SPR_3);
}

if (strcmp(nama_barang,"SS2-V5")==0){
data->SS2_V5 += total;
printf("Jumlah stock SS2-V5 = %d \n", data->SS2_V5);
}

if (strcmp(nama_barang,"SPG1-V3")==0){
data->SPG1_V3 += total;
printf("Jumlah stock SPG1-V3 = %d \n", data->SPG1_V3);
}

if (strcmp(nama_barang,"MINE")==0){
data->MINE += total;
printf("Jumlah stock MINE = %d \n", data->MINE);
}
}

}
}
