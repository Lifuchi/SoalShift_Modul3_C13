#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];

void* mencari(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
}
int main(void)
{
    int i=0;
    int err;
    while(i < 2){
	err=pthread_create(&(tid[i]),NULL,&mencari,NULL);//membuat thread
	i++;
	}
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
