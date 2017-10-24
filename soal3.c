#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int kep=100,loh=20;
pthread_t tid[5];

void* lohan(){ //thread 1
	loh+=10;
	if(loh>100) printf("game over! lohan overweight\n");
	else printf("Status lohan(+10) : %d\n",loh);
}
void* kepiting(){
	kep+=10;
	if(kep>100) printf("game over! kepiting overweigth\n");
	else printf("Status kepiting(+10) : %d\n", kep);
}
void* mati(){
	if(kep<=0) {
		printf("Game Over! Kepiting mati\n");
		exit(1);
	}
	else if(loh<=0){
		printf("Game Over! Lohan Mati\n");
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
	int a; int quit=0;
	while(quit!=1){
	printf("fitur list :\n1. beri makan lohan\n2. beri makan kepiting\n3. cek status lohan\n4. cek status kepiting\n5. keluar program\npilih jenis fitur : ");
	scanf("%d",&a);
	if(a==1) pthread_create(&(tid[0]),NULL,&lohan,NULL);
	else if(a==2) pthread_create(&(tid[1]),NULL,&kepiting,NULL);
	else if(a==5) {quit=1; break;}
	pthread_create(&(tid[2]),NULL,&mati,NULL);
	pthread_create(&(tid[3]),NULL,&timer,NULL);
	pthread_create(&(tid[4]),NULL,&timer1,NULL);
	for(int i=0;i<5;i++) pthread_join(tid[i],NULL);
	}
	return 0;
}
