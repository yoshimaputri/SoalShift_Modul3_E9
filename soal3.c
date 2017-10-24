#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
int kep=100,loh=100;
pthread_t tid[3];
void* binatang(){ //thread 1
	while(kep > 0 && loh > 0){
		char a,b;
		printf("Beri makan lohan ?(Y/N) \n");
		scanf("%c",&a);
		if(a=='y'||a=='Y') loh+=10;
		printf("Beri makan kepiting ?(Y/N) \n");
		scanf("%c",&b);
		if(b=='y'||b=='Y') kep+=10;
		sleep(10);
		printf("Status Kepiting = %d\n",kep);
		printf("Status Lohan = %d\n",loh);
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