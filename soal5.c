#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
char kata1[20]; char kata2[20];
int i;

void* cari()
{
	printf("%s", kata1);
}

void* carilagi()
{
	printf("%s", kata2);
}

int main()
{
	scanf("%s", kata1);
	scanf("%s", kata2);
	FILE *path; i=0;
	char *line=NULL;
//	size_t len=0; ssize_t read;
	path=fopen("novel.txt", "r");
//	while(read=getline(&line,&len,path)!=-1){ 
//	if(fgetc(path)!=EOF){ printf("bs");
//		while(getline(path,line)){
//			if(strstr(line,kata1)!=NULL) {printf("nemu "); i++;}
//	} printf("%d", i);
char x; string word;
	while(path!=EOF){
	x=fgets();
	while(x!=' '){
	word=word+x;
x=fgets();
}
printf("%s",word);
}

	fclose(path);
	pthread_create(&(tid[0]),NULL,&cari,NULL);
	pthread_create(&(tid[1]),NULL,&carilagi,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
