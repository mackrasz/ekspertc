#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile int val;

void signal_handler(int sig)
{
    switch (sig)
    {
        case SIGINT:
            printf("Interrupt\n");
            val = 2;
            break;
    }
}

int main(int argc, char** argv)
{
    unsigned int sum = 0;
    int no = 0;

    signal(SIGINT, signal_handler);
    
    val = atoi(argv[1]);
    no = atoi(argv[2]);

    while(no--)
    {
        sum += val;
    }

    printf("%u\n", sum);

    return 0;
}