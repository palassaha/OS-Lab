// Demonstrate the use of POSIX threads

#include<stdio.h>
#include<stdlib.h>  // For exit
#include<unistd.h>  // For sleep
#include<pthread.h> // For pthread functions

void *myThreadFun(void *vargp) {
    sleep(1);
    printf("Printing OS Lab from thread\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    printf("Before Thread\n");

    if (pthread_create(&thread_id, NULL, myThreadFun, NULL) != 0) {
        perror("Failed to create thread");
        exit(1);
    }
    
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}
