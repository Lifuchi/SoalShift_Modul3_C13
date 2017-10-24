#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


pthread_t tid[10];
typedef struct inputan{
	int faktornya;
	int c;
}input;

void* faktorial(void *arg)
{
	struct inputan *ngitung = (struct inputan*)arg;
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0]))
    {
    
    }
    else 
    {
        
    }
    return NULL;
}
int main(void)
{
    input angka;
	angka.c =0;
    while(angka.faktornya != EOF && angka.c < 10 )
    {
        pthread_create(&(tid[angka.c++]),NULL,&faktorial,&angka);
       angka.c++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
