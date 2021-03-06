#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int kep=100,loh=100;
pthread_t tid[2];
void* kepiting(){
	while(1){
		sleep(20);
		kep-=10;
		if(kep<=0 || kep > 100 || loh <=0 || loh > 100) exit(EXIT_FAILURE);
			printf("STATUS KEPITING BERKURANG 15\n");
			printf("HP KEPITING SEKARANG : %d\n",kep);
	}
}
void* lohan(){
	while(1){
		sleep(10);
		loh-=15;
		if(kep<=0||kep>100 || loh<=0 || loh >100) exit(EXIT_FAILURE);
		printf("STATUS LOHAN BERKURANG 10\n");
		printf("HP LOHAN SEKARANG : %d\n",loh);
		
	}
}
int main(){
	pthread_create(&(tid[0]),NULL,&kepiting,NULL);
	pthread_create(&(tid[1]),NULL,&lohan,NULL);
	while(1){
		if(kep>100 || loh > 100 || kep <=0 || loh <= 0){
			if(kep > 100 || kep <= 0) printf("Game Over Kepiting Overweight / Mati\n"); // kalo kepiting darahnya melebihi 100 atau dibawah sama dengan 0
			else printf ("Game Over Lohan Overweight / Mati\n");
			break;
		}
		int menu;
		printf("Pilih yang kamu mau kasih makan!\n");
		printf("1. Kepiting\n");
		printf("2. Lohan\n");
		scanf("%d",&menu);
		if(menu==1){
			printf("Kamu memilih kepiting !\n");
			kep+=10;
			printf("Status Kepiting sekarang : %d\n",kep);
			printf("Status Lohan sekarang : %d\n",loh);
		}
		else if(menu==2){
			printf("Kamu memilih lohan !\n");
			loh+=10;
			printf("Status Kepiting sekarang : %d\n",kep);
			printf("Status Lohan sekarang : %d\n",loh);
		}
		printf("Countdown 5 detik untuk memberi delay makanan\n");
		sleep(5); // ngasih sleep 5 detik biar ga kecepetan ngasih makan.
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
