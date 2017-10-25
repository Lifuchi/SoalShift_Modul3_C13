#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[5];


typedef struct peliharaaan{
	char pet1[100];
	char pet2[100];
	int hp1;
	int hp2;
}input;


void* peliharaan(void *arg)
{
	struct peliharaaan *p =  (struct peliharaaan*)arg;
	pthread_t id= pthread_self();
	while(1){	
	if(pthread_equal(id,tid[0])){
		sleep(10);	
		p->hp1 = p->hp1-15;
		if (p->hp1 <= 0)  exit(EXIT_FAILURE);				
	}
	else {
		sleep(20);		
		p->hp2 = p->hp2-10;						
		if (p->hp2 <= 0)  exit(EXIT_FAILURE);
		}	
	}
   	return NULL;

}
int main(void)
{
	input pet;
        int i=0;
	int pilih ;
	strcpy(pet.pet1,"Lohan");
	strcpy(pet.pet2,"Kepiting");
	pet.hp1 = 100;
	pet.hp2 = 100;
	printf("Merawat Peliharaan Kolom\n");
	printf("Klik 1 untuk memberi makan Lohan \nKlik 2 untuk memberi makan Kepiting \n");

	
	while(pet.hp2 > 0 && pet.hp1 > 0){
	pthread_create(&(tid[0]),NULL,&peliharaan,&pet);
	pthread_create(&(tid[1]),NULL,&peliharaan,&pet);
	scanf("%d", &pilih);
	
	if(pilih == 1){

	}
	else if(pilih == 2){

	}
	else if(pilih == 3){
	printf("%s status : %d \n",pet.pet1 ,pet.hp1);
	printf("%s status : %d \n",pet.pet2 ,pet.hp2);

	}
}

	
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
