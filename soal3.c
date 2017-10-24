#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
int kep=100,loh=100;
pthread_t tid[2];
void* lohan(){ //thread 1
	char a;
	while(kep>0){
		printf("Berikan makan kepada Lohan(Y/N) ? \n");
		scanf("%c",a);
		if(a=="Y" || a=="y") loh+=10;
		
	}
}
void* kepiting(){ //thread 2
	while(loh>0){

	}

}
int main(){
	pthread_create(&(tid[0]),NULL,&lohan,NULL);
	pthread_create(&(tid[1]),NULL,&kepiting,NULL);
	for(int i=0;i<2;i++) pthread_join(tid[i],NULL);
}