#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];

void* cari()
{
}

void* carilagi()
{
}

int main()
{
	pthread_create(&(tid[0]),NULL,&cari,NULL);
	pthread_create(&(tid[1]),NULL,&carilagi,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
