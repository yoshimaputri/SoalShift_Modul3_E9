#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
int kep=100,loh=100;
pthread_t tid[3];
void* binatang(){ //thread 1
	while(kep > 0 && loh > 0){
		char a[20];
		printf("Siapa yang mau diberi makan? \n");
		scanf("%s",a);
		if(a=="kepiting" || a=="Kepiting") kep+=10;
		else if(a=="lohan"|| a=="Lohan") loh+=10;
	}
	if(kep<=0) {
		printf("Game Over Kepiting mati\n");
		exit(1);
	}
	else if(loh<=0){
		printf("Game Over Lohan Mati\n");
		exit(1);
	}

}
void* timer(){
	while(kep>0){
		sleep(20);
		kep-=10;
	}

}
void* timer1(){
	while(loh>0){
		sleep(10);
		loh-=15;
	}
}
int main(){
	pthread_create(&(tid[0]),NULL,&binatang,NULL);
	pthread_create(&(tid[1]),NULL,&timer,NULL);
	pthread_create(&(tid[2]),NULL,&timer1,NULL);
	for(int i=0;i<3;i++) pthread_join(tid[i],NULL);
}