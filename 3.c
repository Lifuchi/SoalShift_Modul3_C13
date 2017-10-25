//belum selesai

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int stats1,stats2;
void *kepiting() {
	while(1)
		{
		if (stats1 <= 0 || stats1 > 100) {
			exit(EXIT_FAILURE);}
}
}
void *lohan() {
	while(1) 
	{
		if (stats2 <= 0 || stats2 > 100) {
				exit(EXIT_FAILURE);}
		}
}

void berimakan(){
}
int main () 	{
	stats1=100;
	stats2=100;
	pthread_t kepiting_t,lohan_t;
	pthread_create (&kepiting_t,NULL,&kepiting,NULL);	
	pthread_create (&lohan_t,NULL,&lohan,NULL);

	while (1) {
		int pil;
		if(stats1 <= 0 || stats1 > 100 || stats2 <= 0 || stats2 > 100) {
			exit(EXIT_FAILURE);
		}
		else {
			printf("1. Lihat status\n2. Berimakan\n");
			scanf ("%d",&pil);

			if (pil==1) {
				printf("Status Kepiting: %d\n", stats1);
				printf("Status Lohan: %d\n", stats2);
			}
			else if (pil==2) {
				berimakan();
			}
		}
}
}

