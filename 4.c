#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


pthread_t tid[50];

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
	char c;
	i =0;

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
	
	int t =0;
	
    for(t = 0 ; t < i ;t++){
	pthread_join(tid[t],NULL);
 	}
    return 0;
}
