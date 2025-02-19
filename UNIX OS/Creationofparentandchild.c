    // 2) Write programs using the following UNIX operating system calls for fork, getpid
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>  // Required for exit()

int main() 
{
    int pid, pid1, pid2;
    
    pid = fork();  // Create a child process
    
    if (pid == -1) {
        printf("Error in process creation\n");
        exit(1);  // Exit if fork fails
    }
    
    if (pid != 0) {  // Parent process
        pid1 = getpid();
        printf("\nThe parent process ID is %d\n", pid1);
    } else {  // Child process
        pid2 = getpid();
        printf("\nThe child process ID is %d\n", pid2);
    }

    return 0;
}
