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

key_t sharedKEY = ftok("#", 'A');
int sharedID = shmget(sharedKEY, sizeof(struct Memory), IPC_CREAT | 0666);

s = (struct stock *) shmat(sharedID, NULL, 0);

int pilih;

struct stock *s;
char senjata[100];
int total;

while(1)
{
printf("1. Lihat stock senjata\n");
printf("2. Beli senjata\n");
scanf("%d", &pilih);

if (pilih == 1)
{
printf("MP4A1 %d\n", s.MP4A1);
printf("PM2-V1 %d\n", s.PM2_V1);
printf("SPR-3 %d\n", s.SPR_3);
printf("S2-V5 %d\n", s.SS2_V5);
printf("SPG1-V3 %d\n", s.SPG1_V3);
printf("MINE %d\n", s.MINE);
}
else if(pilih == 2){
scanf("%s %d", senjata, &total);

if (strcmp(senjata,"MP4A1")==0){
 if (total > s.MP4A1){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 s.MP4A1 = s.MP4A1-total;
 }
}

if (strcmp(senjata,"PM2-V1")==0){
 if (total > s.PM2_V1){
 printf("stock tidak cukup\n");
 }
 else{
 s.PM2_V1 = s.PM2_V1-total;
 }

}

else if (strcmp(senjata,"SPR-3")==0){
 if (total > s.SPR_3){
 printf("stock tidak cukup\n");
 }
 else{
 s.SPR_3 -= total;
 }
}

else if (strcmp(senjata,"SS2-V5")==0){
 if (total > s.SS2_V5){
 printf("stock tidak cukup\n");
 }
 else{
 s.SS2_V5 = s.SS2_V5-total;
 }
}

else if (strcmp(senjata,"SPG1-V3")==0){
 if (total > s.SPG1_V3){
 printf("stock tidak cukup\n");
 }
 else{
 s.SPG1_V3 = s.SPG1_V3-total;
 }

}

else if (strcmp(senjata,"MINE")==0){
 if (total > s.MINE){
 printf("stock tidak cukup\n");
 }
 else{
 s.MINE = s.MINE-total;
 }
}
 else
 printf("barang tidak ada\n");
}

}
}
