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

void* add(){status=0;
while(1){
	printf("\n%s - berapa lubang yg akan diisi ranjau? ",player1);
	scanf("%d", &x);
	printf("%s - lubang mana yg akan diisi? ",player1);
	while(x--) {
		scanf("%d", &nolubang);
		board1[nolubang]=1;
	}
	printf("\n%s - berapa lubang yg akan diisi ranjau? ",player2);
	scanf("%d", &x);
	printf("%s - lubang mana yg akan diisi? ",player2);
	while(x--) {
		scanf("%d", &nolubang);
		board2[nolubang]=1;
	}

	printf("\n%s beri tebakan pada %s\nmanakah EMPAT lubang yg AMAN?\n",player1,player2);
	printf("%s menjawab : ",player2);
	scanf("%d %d %d %d",&tebak[0],&tebak[1],&tebak[2],&tebak[3]);
	for(int b=0;b<4;b++){
		if(board1[tebak[b]]==1)//jika jawaban p2 salah
			score1+=1;
		else score2+=1; //jika jawaban p2 benar
	}
	printf("score %s now : %d\n",player1,score1);
	printf("score %s now : %d\n",player2,score2);
	if(score1>=10) break; if(score2>=10) break;

	printf("\n%s beri tebakan pada %s\nmanakah EMPAT lubang yg AMAN?\n",player2,player1);
	printf("%s menjawab : ",player1);
	scanf("%d %d %d %d",&tebak[0],&tebak[1],&tebak[2],&tebak[3]);
	for(int b=0;b<4;b++){
		if(board2[tebak[b]]==1)//jika jawaban p2 salah
			score2+=1;
		else score1+=1; //jika jawaban p2 benar
	}
	printf("score %s now : %d\n",player1,score1);
	printf("score %s now : %d\n",player2,score2);
	if(score1>=10) break; if(score2>=10)  break;
}
status=1;
}
void* gameover(){
while(status!=1) {}
if(score1>=10) {printf("%s menang. skor : %d\n",player1,score1); }
	if(score2>=10) {printf("%s menang. skor : %d\n",player2,score2);}
	int hit1=0,hit2=0;
	for(int i=1;i<17;i++){
		if(board1[i]==1) hit1++;
		if(board2[i]==1) hit2++;
	}
	if(hit1==16 && hit2==16) {printf("semua lubang dari kedua pemain sudah terisi ranjau");}
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
	pthread_create(&(tid[1]),NULL,&gameover,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}
