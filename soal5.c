#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
int i; FILE *path; int status;

void* cari(void *arg)
{
	status=0;
	path=fopen("novel.txt", "r");
	if(strcmp((char*)arg,"ifah")==0) printf("sip");
	fclose(path);
	status=1;
}

void* carilagi()
{
	while(status!=1) {}
}

int main(int argc, char *argv[])
{
	printf("%s", argv[1]);
	pthread_create(&(tid[0]),NULL,&cari,(void*)argv[1]);
	pthread_create(&(tid[1]),NULL,&carilagi,(void*)argv[2]);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
