#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[3];
int t[3];

void* faktorial1() //menjalankan thread 1
{
	int range=t[0], result=1;
	while(range>0){
	 result*=range; range--;
	}
	printf("Hasil %d! = %d\n", t[0], result);
}



int main()
{
	int i=hit=3,a; char c; int temp;
	scanf("%d %d %d", &t[0],&t[1],t[2]);
	//fungsi sort biar output nya urut
	while(hit--){
	 for(a=0;a<i;a++){
	  if(t[a]>t[a+1]){
		temp=t[a]; t[a]=t[a+1]; t[a+1]=temp;
	  }
	 }
	}
	pthread_create(&(tid[0]),NULL,&faktorial1,NULL);
	pthread_create(&(tid[1]),NULL,&faktorial2,NULL);
	pthread_create(&(tid[2]),NULL,&faktorial3,NULL);
	for(a=0;a<i;a++) pthread_join(tid[a],NULL);
	return 0;
}
