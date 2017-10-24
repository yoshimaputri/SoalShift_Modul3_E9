#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <sys/wait.h>
char weapon[6][8]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
int stock[6]={"19","10","13","0","5","9"};
int main(){
	key_t keyp= 1234;
	int shmid = shmget(keyp,sizeof(int), IPC_CREAT | 0666);
	if(shmid<0){
		perror("shmget");
		exit(1);
	}
	shm = shmat(shmid,NULL,0);
	if(shm == (char*) -1){
		perror("shmat");
		exit(1);
	}

}