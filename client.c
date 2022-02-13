#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("argument error!!\n");
        return (1);
    }

    printf("argv[1]:%s\n", argv[1]);
    kill(atoi(argv[1]), SIGUSR1);

    return (0);
}