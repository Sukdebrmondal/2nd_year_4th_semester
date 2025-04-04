
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