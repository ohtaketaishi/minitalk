#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void    sighandler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("0\n");
    }
    if (signum == SIGUSR2)
    {
        printf("1\n");
    }
}
int main()
{
    printf("PID:%d\n", getpid());

    signal(SIGUSR1, &sighandler);
    signal(SIGUSR2, &sighandler);
    
    while(1);
    return (0);
}