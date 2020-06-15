#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

typedef enum err_code
{
    no_error = 0,
    connection_error = 1,
    measurement_error = 2
} err_code;

jmp_buf target;

void setup_errors();

int connection1();
int connection2();
int connection3();

int measure1();
int measure2();

void connect_to_device();
void measure();
void disconnect_from_device();

int main()
{
    setup_errors();

    connect_to_device();
    measure();
    disconnect_from_device();
    
    return 0;
}

void setup_errors()
{

    switch(setjmp(target))
    {
        case 0:
            break;
        case connection_error:
            printf("Connection error\n");
            exit(connection_error);
        case measurement_error:
            printf("Measurement error\n");
            disconnect_from_device();
            exit(measurement_error);
        default:
            printf("Unknown error\n");
            exit(-1);
    }

}

int connection1()
{
    return 0;
}

int connection2()
{
    return 0;
}

int connection3()
{
    return 0;
}

void connect_to_device()
{
    printf("Allocating resources\n");
    if (connection1() != 0)
        goto ERR;

    if (connection2() != 0)
        goto ERR;

    if (connection3() != 0)
        goto ERR;

    return;
    
    ERR:
        printf("Free resources\n");
        longjmp(target, connection_error);
}

int measure1()
{
    return 0;
}

int measure2()
{
    return 1;
}

void measure()
{
    if (measure1() != 0)
        longjmp(target, measurement_error);
    if (measure2() != 0)
        longjmp(target, measurement_error);

    printf("Measurement taken\n");
    return;
}

void disconnect_from_device()
{
    printf("Free resources\n");
}