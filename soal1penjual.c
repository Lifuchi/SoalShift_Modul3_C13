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

