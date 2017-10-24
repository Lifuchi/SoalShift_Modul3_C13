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
	int i=0;
	struct inputan *ngitung = (struct inputan*)arg;
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0]))
    {
	
    
    }
    else 
    {
	pthread_equal(id,tid[angka.c++])
        
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
    pthread_join(tid[2],NULL);
    pthread_join(tid[3],NULL);
    pthread_join(tid[4],NULL);
    pthread_join(tid[5],NULL);
    pthread_join(tid[6],NULL);
    pthread_join(tid[7],NULL);
    pthread_join(tid[8],NULL);
    pthread_join(tid[9],NULL);

    return 0;
}
