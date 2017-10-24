#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];


typedef struct cari{
	char n[100];
	int c;
}input;


void* mencari(void *arg)
{
  struct cari *ngitung =  (struct cari*)arg;
	unsigned long i =0;
	pthread_t id= pthread_self();
   if(pthread_equal(id,tid[0])){
	printf("nama sudah masuk, %s", ngitung->n);
	}
}
int main(void)
{
    int i=0;
    int err;
    input nama;
    while(i < 2){
	scanf("%s",nama.n);
	err=pthread_create(&(tid[i]),NULL,&mencari,&nama);
	i++;
	}
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
