// Demonstrate the creation of a process using fork() system call and print the process id and the parent process and child process

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void demo() {
    int x = 10; 
    pid_t p_id, p_pid;

    if (fork() == 0) { 
        p_id = getpid();     
        p_pid = getppid();   
        printf("Child process: pid=%d, parent pid=%d, x=%d\n", p_id, p_pid, ++x);
    } else { 
        p_id = getpid();    
        printf("Parent process: pid=%d, x=%d\n", p_id, --x);
    }
}

int main() {
    demo();
    return 0;
}
