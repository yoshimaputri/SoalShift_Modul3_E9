#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
int i; FILE *path; int status; char arr[1001]; char *line;

void* cari(void *arg)
{
	status=0; i=0;
	char kata1[20]; strcpy(kata1,arg);
	path=fopen("novel.txt", "r");
	while(fscanf(path,"%s",arr)!=EOF){
		if(strstr(arr,kata1)!=0) i++;
	}
	printf("%s : %d\n", kata1, i);
	fclose(path);
	status=1;
}

void* carilagi(void *arg)
{
	while(status!=1) {}
	i=0;
	char kata2[20]; strcpy(kata2,arg);
	path=fopen("novel.txt", "r");
	while(fscanf(path,"%s",arr)!=EOF){
		if(strstr(arr,kata2)!=0) i++;
	}
	printf("%s : %d\n", kata2, i);
	fclose(path);
}

int main(int argc, char *argv[])
{
	pthread_create(&(tid[0]),NULL,&cari,(void*)argv[1]);
	pthread_create(&(tid[1]),NULL,&carilagi,(void*)argv[2]);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
