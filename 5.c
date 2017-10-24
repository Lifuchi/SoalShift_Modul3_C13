#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[2];


typedef struct cari{
	char n[1000];
	char n2[1000];
	int c;
	int c2;
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
	else if(pthread_equal(id,tid[1])){
	
	FILE *fnovel;
	char ch;
	char string[1000];
	fnovel = fopen("Novel.txt", "r");
	while  (!feof(fnovel)) {
		fscanf(fnovel,"%s",string);	
		if(strstr(string,ngitung->n2) != 0) ngitung->c2++;
	
		}
	fclose(fnovel);
	printf("%s : %d\n",ngitung->n2,ngitung->c2);
	
	}
	return NULL;
}
int main(void)
{
    int i=0;
    int err;
    input nama;
	scanf("%s",nama.n);
	scanf("%s",nama.n2);
	nama.c = 0;
	nama.c2 = 0;
	while (i <2 ){
	err=pthread_create(&(tid[i]),NULL,&mencari,&nama);
	i++;
	}

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
