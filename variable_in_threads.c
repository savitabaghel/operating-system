#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int aglobal = 0;

void *myThread(void *x)
{
    int *myid = (int *)x;
    static int astatic = 0;
    int alocal =0;
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++astatic, ++aglobal, ++alocal);
}

int main()
{
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_create(&tid1, NULL, myThread, (void *)&tid1);
    pthread_create(&tid2, NULL, myThread, (void *)&tid2);
    pthread_create(&tid3, NULL, myThread, (void *)&tid3);
    pthread_exit(NULL);
    return 0;
}
