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
key_t KEY;
int pilih;

struct stock s;
char senjata[100];
int total;

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
printf("MP4A1 %d\n", s.MP4A1);
printf("PM2-V1 %d\n", s.PM2_V1);
printf("SPR-3 %d\n", s.SPR_3);
printf("S2-V5 %d\n", s.SS2_V5);
printf("SPG1-V3 %d\n", s.SPG1_V3);
printf("MINE %d\n", s.MINE);
}

