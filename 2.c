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
	int lub;
}pmn;


 
void* pemain1(void *arg)
{
    struct player *maen =  (struct player*)arg;
    char t;
    status = 1;	
    int flag = 4;

    while(flag != 0){
	printf("\nPlayer 1 silahkan memilih angka untuk meletakkan ranjau sebanyak 1-4 \n");
	scanf("%d",&maen->lub,&t);
	maen->mine[maen->lub] = 1;
	flag--; 
    }
	status = 0;
    return NULL;
}


void* pemain2(void *arg)
{
    struct player *ngitung =  (struct player*)arg;
    while(status != 1)
    {

    }

}
 
int main(void)
{
    pmn plyr1,plyr2;
    plyr1.poin = 0;
    plyr2.poin = 0;
    memset(plyr1.mine , 0 , 16);
    memset(plyr2.mine, 0 , 16);
    
    pthread_create(&(tid1), NULL, &pemain1, &plyr1);
    pthread_create(&(tid2), NULL, &pemain2, &plyr2);
 
    printf("poin pemain 1 = \n",plyr1.poin );
    printf("poin pemain 2 = \n",plyr2.poin );
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
