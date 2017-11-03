#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
pthread_mutex_t lock;

typedef struct player{
	int mine[17];
	int poin;
	int lub;
	int mine2[17];
	int poin2;
	int lub2;
	int htung;
	int htung2;
}pmn;


 
void* pemain1(void *arg)
{
	pthread_mutex_lock(&lock);
    struct player *maen =  (struct player*)arg;
    char t;
	int flag;
    printf("Player 1 silahkan memilih angka untuk meletakkan ranjau sebanyak 1-4 pada 16 lubang tersedia \n");
	printf("Berapa ranjau yg akan dimasukkan?\n");
	scanf("%d",&flag);
		printf("masukkan\n");
    while(flag != 0){
	scanf("%d",&maen->lub,&t);
	if (maen->mine[maen->lub] == 0) {maen->mine[maen->lub] = 1; maen->htung++;}
	else { printf("ranjau sudah ada , pilih lubang lainnya\n"); flag++; }
	flag--;
    }
    printf("ranjau sudah dipasang\n");
 
    printf("Player 2 silahkan memilih 4 lubang\n");
    int i, j ;
    int x;
	for (i = 0 ; i < 4 ; i++)
	{
		scanf("%d", &x);
		if(maen->mine[x] == 1) {printf("anda benar\n");maen->poin2 += 1;maen->mine[x] = 12;}
		else if(maen->mine[x] == 0) {printf("anda salah\n");maen->poin += 1;}
		else{printf("anda sudah memilih sebelumnya , pilih lubang lain\n");i--;} 	
	}
	
	status = 1;
			printf("poin pemain 1 =%d \n",maen->poin );
		printf("poin pemain 2 =%d \n",maen->poin2 );
	if (maen->poin >=10 || maen->poin2 >=10){
		exit(EXIT_FAILURE);}
	pthread_mutex_unlock(&lock);	
    return NULL;
}


void* pemain2(void *arg)
{
	pthread_mutex_lock(&lock);
    struct player *maen =  (struct player*)arg;
        char t;
	int flag;
    printf("Player 2 silahkan memilih angka untuk meletakkan ranjau sebanyak 1-4 dalam 16 lubang tersedia \n");
	printf("Berapa ranjau yg akan dimasukkan?\n");
	scanf("%d",&flag);
	printf("masukkan\n");
    while(flag != 0){
	scanf("%d",&maen->lub2,&t);
	if (maen->mine2[maen->lub2] == 0) {maen->mine2[maen->lub2] = 1;maen->htung2++;}
	else {printf("ranjau sudah ada , pilih lubang lainnya\n"); flag++;} 
	flag--;
    }

    printf("ranjau sudah dipasang\n");
    printf("Player 1 silahkan memilih 4 lubang\n");
    int i, j ;
    int x;
	for (i = 0 ; i < 4 ; i++)
	{
		scanf("%d", &x);
		if(maen->mine2[x] == 1) {printf("anda benar\n");maen->poin += 1;maen->mine2[x] = 12;}
		else if (maen->mine2[x] == 0){printf("anda salah\n");maen->poin2 += 1;} 	
		else {printf("anda sudah memilih sebelumnya , pilih lubang lain\n");i--;}	
	}	
				printf("poin pemain 1 =%d \n",maen->poin );
		printf("poin pemain 2 =%d \n",maen->poin2 );
	if (maen->poin >=10 || maen->poin2 >=10 || maen->htung2 == 16 || maen->htung == 16){
		exit(EXIT_FAILURE);}
    
		pthread_mutex_unlock(&lock);    
return 0;	
    
}
 
int main(void)
{
    pmn plyr;
	int i,lol = 2;
    plyr.poin = 0;
    plyr.poin2 = 0;
    plyr.htung = 0;
    plyr.htung2 = 0;
	for (i = 1 ; i < 17 ; i++){
		plyr.mine[i] = 0;
	}
	for (i = 1 ; i < 17 ; i++){
		plyr.mine2[i] = 0;
	}

	for(i = 0; i < 15 ; i++){
    		pthread_create(&(tid1), NULL, &pemain1, &plyr);
    		pthread_create(&(tid2), NULL, &pemain2, &plyr);	
	}
		


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
