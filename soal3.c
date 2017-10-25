#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int kep,loh;
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
