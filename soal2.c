#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

int main(){
	pthread_create(&(tid1),NULL,&p1,NULL);
	pthread_create(&(tid2),NULL,&p2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}