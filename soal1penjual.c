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
struct stock *s;
char nama_barang[100];

key_t KEY = ftok("#", 'A');
int sharedID = shmget(sharedKEY, sizeof(struct Memory), IPC_CREAT | 0666);

key_t KEY;
int pilih;

struct stock s;
//char senjata[100];
int total;
s = (struct stock *) shmat(sharedID, NULL, 0);

s.MP4A1=0;
s.PM2_V1=0;
s.SPR_3=0;
s.SS2_V5=0;
s.SPG1_V3=0;
s.MINE=0;

while(1)
{
printf("1. Lihat stock senjata\n");
printf("2. Isi stock senjata\n");
scanf("%d", &pilih);

if (pilih == 1)
{
 if(s->MP4A1>0){
 printf("Jumlah MP4A1 = %d\n", data->MP4A1);
 }

 if(s->PM2_V1>0){
 printf("Jumlah PM2-V1 = %d\n", data->PM2_V1);
 }

 if(s->SPR_3>0){
 printf("Jumlah SPR-3 = %d\n", data->SPR_3);
 }

 if(s->SS2_V5>0){
 printf("Jumlah SS2-V5 = %d\n", data->SS2_V5);
 }

 if(s->SPG1_V3){
 printf("Jumlah SPG1-V3 = %d\n", data->SPG1_V3);
 }

 if(s->MINE){
 printf("Jumlah MINE = %d\n", data->MINE);
 }

 else{
 printf("STOK SEMUA KOSONG\n\n");
}
  
}

