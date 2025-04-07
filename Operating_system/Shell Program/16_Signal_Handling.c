
// # 16. Write a system program to implement signal handling.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("\nReceived SIGINT\n");
}
int main()
{
    printf("\nTry to kill me...\nmy pid:%d \nto kill it opening another terminal write 'kill <pid>'\n", getpid());
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\nCant catch...\n");
    while (1)
        sleep(1);
    return 0;
}


// output
// sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ gcc 16_Signal_Handling.c 
// sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ ./a.out

// Try to kill me...
// my pid:9324 
// to kill it opening another terminal write 'kill <pid>'



// sukdeb@sukdeb-OptiPlex-5050:~$ kill 9324


// sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ gcc 16_Signal_Handling.c 
// sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ ./a.out

// Try to kill me...
// my pid:9324 
// to kill it opening another terminal write 'kill <pid>'
// Terminated
