#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
char player1[50],player2[50]; int status;
int score1=0,score2=0; int tebak[4];
int board1[17]; int board2[17];
int in,x,nolubang;

void* add(){
	status=0;
	printf("p1 : berapa lubang yg akan diisi ranjau? ");
	scanf("%d", &x);
	printf("p1 : lubang mana yg akan diisi? ");
	while(x--) {
		scanf("%d", &nolubang);
		board1[nolubang]=1;
	}
	printf("\np2 : berapa lubang yg akan diisi ranjau? ");
	scanf("%d", &x);
	printf("p2 : lubang mana yg akan diisi? ");
	while(x--) {
		scanf("%d", &nolubang);
		board2[nolubang]=1;
	}
	status=1;
}
void* ask(){
	while(status!=1){}
	printf("\np1 beri tebakan pada p2\nada EMPAT lubang yg AMAN\nlubang manakah itu?\n");
	printf("p2 menjawab : ");
	scanf("%d %d %d %d",&tebak[0],&tebak[1],&tebak[2],&tebak[3]);
	for(int b=0;b<4;b++){
		if(board1[tebak[b]]==1)//jika jawaban p2 salah
			score1+=1;
		else score2+=1; //jika jawaban p2 benar
	}
	printf("score p1 now : %d\n",score1);
	printf("score p2 now : %d\n", score2);

	printf("\np2 beri tebakan pada p1\nada EMPAT lubang yg AMAN\nlubang manakah itu?\n");
	printf("p1 menjawab : ");
	scanf("%d %d %d %d",&tebak[0],&tebak[1],&tebak[2],&tebak[3]);
	for(int b=0;b<4;b++){
		if(board2[tebak[b]]==1)//jika jawaban p2 salah
			score2+=1;
		else score1+=1; //jika jawaban p2 benar
	}
	printf("score p1 now : %d\n",score1);
	printf("score p2 now : %d\n", score2);
}
int main(){
	printf("Masukkan nama untuk Player 1:\n");
	scanf("%s",player1);
	printf("Masukkan nama untuk Player 2:\n");
	scanf("%s",player2);
	for(int i=1;i<17;i++){
		board1[i]=0; board2[i]=0;
	}
	pthread_create(&(tid[0]),NULL,&add,NULL);
	pthread_create(&(tid[1]),NULL,&ask,NULL);
while(1){
	if(score1>=10) {printf("p1 menang. skor : %d\n", score1); break;}
	if(score2>=10) {printf("p2 menang. skor : %d\n", score2); break;}
	int hit1=0,hit2=0;
	for(int i=1;i<17;i++){
		if(board1[i]==1) hit1++;
		if(board2[i]==1) hit2++;
	}
	if(hit1==16 && hit2==16) {printf("semua lubang dari kedua pemain sudah terisi ranjau"); break;}
}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
//	printf("fitur list :\n1. cek status\n");
//	while(1){
//		scanf("%d",&in);
//		printf("player 1 : %d\n", score1);
//		printf("player 2 : %d\n", score2);
//	}
}
