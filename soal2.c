#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
char player1[50],player2[50];
int score=0,score1=0;
char board[17][17];
void* player(){
	pthread_t id=pthread_self();
	if(pthread_equal(id,tid[0])){

	}
	else if(pthread_equal(id,tid[1])){

	}
}
int main(){
	while(1){
		printf("Masukkan nama untuk Player 1:\n");
		scanf("%s",player1);
		printf("Masukkan nama untuk Player 2:\n");
		scanf("%s",player2);
		for(int i=0;i<16;i++){
			for(int j=0;j<16;j++){
				board[i][j]=0;
			}
		}
	}
}