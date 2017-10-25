#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[3];
int t[3];
int status;

void* faktorial1() //menjalankan thread 1
{
	status=0;
	int range=t[0], result=1;
	while(range>0){
	 result*=range; range--;
	}
	status=1;
	printf("Hasil %d! = %d\n", t[0], result);
}

void* faktorial2() //menjalankan thread 2
{
	while(status!=1){}
	int range=t[1], result=1;
	while(range>0){
	 result*=range; range--;
	}
	status=2;
	printf("Hasil %d! = %d\n", t[1], result);
}

void* faktorial3() //menjalankan thread 3
{
	while(status!=2){}
	int range=t[2], result=1;
	while(range>0){
	 result*=range; range--;
	}
	printf("Hasil %d! = %d\n", t[2], result);
}

int main(int argc,char *argv[])
{
	int i=3,hit=i,a; int temp;
	t[0]=atoi((char*)argv[1]); t[1]=atoi((char*)argv[2]); t[2]=atoi((char*)argv[3]);
	//fungsi sort biar output nya urut
	while(hit--){
	 for(a=0;a<i-1;a++){
	  if(t[a]>t[a+1]){
		temp=t[a]; t[a]=t[a+1]; t[a+1]=temp;
	  }
	 }
	}
//	for(a=0;a<i;a++) printf("%d ",t[a]);
	pthread_create(&(tid[0]),NULL,&faktorial1,NULL);
	pthread_create(&(tid[1]),NULL,&faktorial2,NULL);
	pthread_create(&(tid[2]),NULL,&faktorial3,NULL);
	for(a=0;a<i;a++) pthread_join(tid[a],NULL);
	return 0;
}
