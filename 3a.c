#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[2];


typedef struct peliharaaan{
	char pet1[100];
	char pet2[100];
	int hp1;
	int hp2;
}input;


void* peliharaan(void *arg)
{
	struct peliharaaan *p =  (struct peliharaaan*)arg;
	pthread_t\n id= pthread_self();
	printf("%s",p->pet1);
   	return NULL;
}
int main(void)
{
	input pet;
        int i=0;
	strcpy(pet.pet1,"Lohan");
	strcpy(pet.pet1,"Kepiting");
	pet.hp1 = 100;
	pet.hp2 = 100;
	pthread_create(&(tid[i]),NULL,&peliharaan,&pet);
	

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
