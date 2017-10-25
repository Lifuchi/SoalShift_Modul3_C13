#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


pthread_t tid[11];

typedef struct inputan{
	long long int f[100];
	long long int c;
}input;

void* faktorial(void *arg)
{
	long long int i;
	long long int itung =1;
	struct inputan *N = (struct inputan*)arg;
	pthread_t id=pthread_self();
	int b = 0;	
	for(b = 0; b < N->c ; b++){
    	if(pthread_equal(id,tid[b])){
	
	for(i = 1 ; i <= N->f[b]  ; i++ )
		{
		itung *=i;  	
		}
	printf("Hasil %lld! = %lld\n",N->f[b],itung);
	}
    }
    
    return NULL;
}
int main(void)
{	int i , j;
    input angka;
	angka.c =0;
	i =0;
	char c;
    while(1)
    {
	scanf("%lld%c",&angka.f[i],&c); i++;  
	if(c == '\n') break;
    }
	angka.c = i;
	j = 0;
    while (j < i)
    {
	pthread_create(&(tid[j]),NULL,&faktorial,&angka);j++;}
	
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
