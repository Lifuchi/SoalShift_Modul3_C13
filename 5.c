#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

pthread_t tid[2];
char *n[100];

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
	for (b = 0 ; b <= ngitung->t ; b++ ){
 	  if(pthread_equal(id,tid[b])){
	FILE *fnovel;
	char ch;
	char string[1000];
	fnovel = fopen("Novel.txt", "r");

	while  (!feof(fnovel)) {
		fscanf(fnovel,"%s",string);	
		if(strstr(string,n[b]) != 0) ngitung->c++;
		}
	fclose(fnovel);
	printf("%s : %d\n",n[b],ngitung->c);
	}
	}
	
	return NULL;
}
int main(int argc ,char *argv[])
{
    int i=0, j =0;
    int err;
	char temp[100];
    input nama;
    
     while(1)
    {	if(argv[i+1] == NULL) break;
	nama.n2[i] = argv[i+1];	
	i++;  
    }
	nama.t = i;
	nama.c = 0;
	while (j < 2 ){
	err=pthread_create(&(tid[j]),NULL,&mencari,&nama);
	j++;
	}

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    return 0;
}
