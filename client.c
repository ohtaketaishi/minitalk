#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void    print_int32_t(int32_t hoge)
{
    int32_t base = 1;
    int32_t ans = 0;

    while (hoge > 0)
    {
        ans = ans + ( hoge % 2 ) * base;
        hoge = hoge / 2;
        base = base * 10;
    }

    printf("bit列は:%dです。", ans);
}

int32_t check_bynary(int32_t bit_line)
{
    int32_t bynary;
    
    bynary = bit_line & 00000000000000000000000000000001;
    return (bynary);
}

void    send_char(char *pid, int32_t a)
{
    int i = 0;

    while (i < 32)
    {
        if (!(check_bynary(a)))
            kill(atoi(pid), SIGUSR1);
        else
            kill(atoi(pid), SIGUSR2);
        a = a >> 1;
        i++;
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("argument error!!\n");
        return (1);
    }


    printf("argv[1]:%s\n", argv[1]);
    send_char(argv[1], 'a');
    return (0);
}