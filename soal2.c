#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int status2;

typedef struct player{
	int mine[17];
	int poin;
	int lub;
}pmn;


 
void* pemain1(void *arg)
{
    struct player *maen =  (struct player*)arg;
    char t;
    while(status != 0 )
    {

    }
    status = 0;	
    int flag = 4;
    printf("\nPlayer 1 silahkan memilih angka untuk meletakkan ranjau sebanyak 1-4 \n");
    while(flag != 0){
	scanf("%d",&maen->lub,&t);
	maen->mine[maen->lub] = 1;
	flag--; 
    }
    printf("ranjau sudah dipasang\n");
    status = 1;
    printf("Player 1 silahkan memilih 4 lubang\n");
    int i, j ;
    int x;
	for (i = 0 ; i < 4 ; i++)
	{
		scanf("%d", &x);
		if(maen->mine[x] == 1) {printf("anda benar\n");maen->poin += 1;}
		else {printf("anda salah\n");} 	
	}
	printf("poin player 1 : %d\n",maen->poin);
	status = 1;
    return NULL;
}


void* pemain2(void *arg)
{
    struct player *maen2 =  (struct player*)arg;
    while(status != 1 )
    {

    }
    status = 0;
    char t;
    int flag = 4;
    printf("\nPlayer 2 silahkan memilih angka untuk meletakkan ranjau sebanyak 1-4 \n");
    while(flag != 0){
	scanf("%d",&maen2->lub,&t);
	maen2->mine[maen2->lub] = 1;
	flag--; 
    }
    printf("ranjau sudah dipasang\n");
    printf("Player 2 silahkan memilih 4 lubang\n");
    int i, j ;
    int x;
	for (i = 0 ; i < 4 ; i++)
	{
		scanf("%d", &x);
		if(maen2->mine[x] == 1) {printf("anda benar\n");maen2->poin += 1;}
		else {printf("anda salah\n");} 	
	}
	printf("poin player 2 : %d\n",maen2->poin);
    status = 1;
return 0;	
    
}
 
int main(void)
{
    pmn plyr1,plyr2;
    plyr1.poin = 0;
    plyr2.poin = 0;
    memset(plyr1.mine , 0 , 16);
    memset(plyr2.mine, 0 , 16);
    status = 1;
    
    pthread_create(&(tid1), NULL, &pemain1, &plyr1);
    pthread_create(&(tid2), NULL, &pemain2, &plyr2);

    printf("poin pemain 1 =%d \n",plyr1.poin );
    printf("poin pemain 2 =%d \n",plyr2.poin );

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
