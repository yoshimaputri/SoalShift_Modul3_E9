#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>
int main(){
	key_t keyp= 1234;
	char weapon[6][8]={"MP4A1", "PM2-V1","SS2-V5","SPR-3","SPG1-V3","MINE"};
	int shmid = shmget(keyp,sizeof(int)*6, IPC_CREAT | 0666);
	if(shmid<0){
		perror("shmget");
		exit(1);
	}
	int *shm;
	shm = shmat(shmid,NULL,0);
	while(1){
		printf("1. pilih 1 untuk lihat stock senjata\n");
		printf("2. pilih 2 untuk membeli senjata\n");
		int pil;
		scanf("%d",&pil);
		if(pil==1){
			for(int i=0;i<6;i++){
				if(shm[i]>0){
					printf("Jumlah %s di stock = %d barang\n",weapon[i],shm[i]);
				}
			}
		}
		if(pil==2){
			char temp[10];
			int jmlh;
			printf("Ketik 'nama barang' 'jumlah stock' \n");
			scanf("%s %d",temp,&jmlh);
			//printf("%s\n",temp);
			for(int i=0;i<6;i++){
				if(!strcmp(weapon[i],temp)){
					if(jmlh>shm[i]) printf("barang di stock tidak cukup\n");
					else shm[i]-=jmlh;
					break;
				}
			}
		}
	}
	shmdt(shm);
	shmctl(shmid,IPC_RMID,NULL);

}