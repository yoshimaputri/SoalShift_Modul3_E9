#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int kep=100,loh=100;
pthread_t tid[7];

void* lohan(){ 
	loh+=10;
	if(loh>100) {printf("game over! lohan overweight\n"); exit(EXIT_FAILURE);}
	else printf("Status lohan(+10) : %d\n",loh);
}
void* kepiting(){
	kep+=10;
	if(kep>100) {printf("game over! kepiting overweigth\n"); exit(EXIT_FAILURE);}
	else printf("Status kepiting(+10) : %d\n", kep);
}
void* statloh(){ printf("Status lohan : %d\n",loh);}
void* statkep(){ printf("Status kepiting : %d\n",kep);}
void* timer(){
	while(kep>0){
		sleep(20);
		kep-=10;
	if(kep<=0){ printf("Game Over! Kepiting Mati\n"); exit(EXIT_FAILURE);}
	}
}
void* timer1(){
	while(loh>0){
		sleep(10);
		loh-=15;
	if(loh<=0){ printf("Game Over! Lohan Mati\n"); exit(EXIT_FAILURE);}
	}
}
int main(){
	int a; 
	pthread_create(&(tid[0]),NULL,&timer,NULL);
	pthread_create(&(tid[1]),NULL,&timer1,NULL);
	printf("fitur list :\n1. beri makan lohan\n2. beri makan kepiting\n3. cek status lohan\n4. cek status kepiting\n5. keluar program\npilih jenis fitur : ");
	while(1){
	scanf("%d",&a);
	if(a==1) pthread_create(&(tid[3]),NULL,&lohan,NULL);
	else if(a==2) pthread_create(&(tid[4]),NULL,&kepiting,NULL);
	else if(a==3) pthread_create(&(tid[5]),NULL,&statloh,NULL);
	else if(a==4) pthread_create(&(tid[6]),NULL,&statkep,NULL);
	else if(a==5) exit(0);
	}
	for(int i=0;i<7;i++) pthread_join(tid[i],NULL);
	return 0;
}
