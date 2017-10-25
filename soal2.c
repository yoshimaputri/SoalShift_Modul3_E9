#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
char player1[50],player2[50];
int score1=0,score2=0;
char board[17];
void* p1(){
	printf("p1 : berapa lubang yg akan diisi ranjau?");
	scanf("%d", &i);
	while(i--){
	printf("p1 : lubang mana yg akan diisi? [no_lubang]");
	scanf("%d", &nolubang);
	board[nolubang]=1;
	}
}
void* p2(){
}
int main(){
	printf("Masukkan nama untuk Player 1:\n");
	scanf("%s",player1);
	printf("Masukkan nama untuk Player 2:\n");
	scanf("%s",player2);
	for(int i=0;i<16;i++){
		board[i]=0;
	}
	pthread_create(&(tid[0]),NULL,&p1,NULL);
	pthread_create(&(tid[1]),NULL,&p2,NULL);
	printf("fitur list :\n1. cek status\n");
	while(1){
		scanf("%d",&in);
		printf("player 1 : %d\n", score1);
		printf("player 2 : %d\n", score2);
	}
	pthread_join(tid[0]);
}
