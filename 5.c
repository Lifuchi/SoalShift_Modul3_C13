#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[2];

typedef struct cari{
	char *n2[100];
	int c;
	int t;
}input;


void* mencari(void *arg)
{
  struct cari *ngitung =  (struct cari*)arg;
	pthread_t id= pthread_self();
	int b = 0;
	for (b = 0 ; b < ngitung->t ; b++ ){
 		ngitung->c = 0;
	if(pthread_equal(id,tid[b])){
	FILE *fnovel;
	char ch;
	char string[1000];
	fnovel = fopen("Novel.txt", "r");

	while  (!feof(fnovel)) {
		fscanf(fnovel,"%s",string);	
		if(strstr(string,ngitung->n2[b]) != 0) ngitung->c++;
		}
	fclose(fnovel);
	printf("%s : %d\n",ngitung->n2[b],ngitung->c);
	fclose(fnovel);
	}
	}
	
	return NULL;
}
int main(int argc ,char *argv[])
{
    int i=0, j =0 , t = 0;
    input nama;
    
     while(argc >= i)
    {	if(argv[i+1] == NULL) break;
	nama.n2[i] = argv[i+1];	
	i++;  
    }
	nama.t = i;
	nama.c = 0;
	while (j < i ){
	pthread_create(&(tid[j]),NULL,&mencari,&nama);
	j++;
	}

  	for(t = 0 ; t < i ;t++){
	pthread_join(tid[t],NULL);
 	}

    return 0;
}
