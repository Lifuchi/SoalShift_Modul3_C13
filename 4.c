#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


pthread_t tid[3];
typedef struct inputan{
	int f;
	int c;
}input;

void* faktorial(void *arg)
{
	int i;
	int itung =1;
	struct inputan *N = (struct inputan*)arg;
    pthread_t id=pthread_self();

    if(pthread_equal(id,tid[0]))
    {
	for(i = 1 ; i <= N->f  ; i++ )
	{
		itung *=i; 
	 	
	}
	printf("%d\n", itung);
    
    }
    else 
    {
	
        
    }
    return NULL;
}
int main(void)
{	int i;
    input angka;
	angka.c =0;
    while(i < 3)
    {
	scanf("%d",&angka.f);
        pthread_create(&(tid[i]),NULL,&faktorial,&angka);
       i++;
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
