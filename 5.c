#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[2];


typedef struct cari{
	char n[100];
	int c;
}input;


void* mencari(void *arg)
{
  struct cari *ngitung =  (struct cari*)arg;
	pthread_t id= pthread_self();
   if(pthread_equal(id,tid[0])){
	FILE *fnovel;
	char ch;
	char string[1000];
	fnovel = fopen("Novel.txt", "r");
	while  (!feof(fnovel)) {
		fscanf(fnovel,"%s",string);	
		if(strstr(string,ngitung->n) != 0) ngitung->c++;
	
		}
	fclose(fnovel);
	printf("%s : %d\n",ngitung->n,ngitung->c);
	
	}
	else{
	
	FILE *fnovel;
	char ch;
	char string[1000];
	fnovel = fopen("Novel.txt", "r");
	while  (!feof(fnovel)) {
		fscanf(fnovel,"%s",string);	
		if(strstr(string,ngitung->n) != 0) ngitung->c++;
	
		}
	fclose(fnovel);
	printf("%s : %d\n",ngitung->n,ngitung->c);
	


	}
}
int main(void)
{
    int i=0;
    int err;
    input nama;
    while(i < 2){
	scanf("%s",nama.n);
	nama.c = 0;
	err=pthread_create(&(tid[i]),NULL,&mencari,&nama);
	i++;
	}
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
