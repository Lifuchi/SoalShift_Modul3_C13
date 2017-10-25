#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;

typedef struct player{
	int mine[16];
	int poin;
}pmn;


 
void* pemain1(void *arg)
{
 
 
    status = 1;
    return NULL;
}


void* pemain2(void *arg)
{
    while(status != 1)
    {

    }

}
 
int main(void)
{
    pmn pemain1,pemain2;
    pmn pemain1.poin = 0;
    pmn pemain2.poin = 0;
	

    pthread_create(&(tid1), NULL, &pemain1, NULL);
    pthread_create(&(tid2), NULL, &pemain2, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
