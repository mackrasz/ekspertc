#include <stdio.h>

typedef enum err_code
{
    no_error = 0,
    connection_error = 1,
    measurement_error = 2
} err_code;

int connection1();
int connection2();
int connection3();

int measure1();
int measure2();

err_code connect_to_device();
err_code measure();
void disconnect_from_device();

int main()
{
    err_code err;
    if ( (err=connect_to_device()) == no_error)
    {
        if ((err=measure()) == no_error)
        {
            disconnect_from_device();
            return 0;
        }
        else
        {
            disconnect_from_device();
            return err;
        }
        
    }
    else
    {
        return err;
    }
    
}

int connection1()
{
    return 0;
}

int connection2()
{
    return 1;
}

int connection3()
{
    return 0;
}

err_code connect_to_device()
{
    printf("Allocating resources\n");
    if (connection1() != 0)
        goto ERR;

    if (connection2() != 0)
        goto ERR;

    if (connection3() != 0)
        goto ERR;

    return no_error;
    
    ERR:
        printf("Free resources\n");
        return connection_error;
}

int measure1()
{
    return 0;
}

int measure2()
{
    return 0;
}

err_code measure()
{
    if (measure1() != 0)
        return measurement_error;
    if (measure2() != 0)
        return measurement_error;

    printf("Measurement taken\n");
    return no_error;
}

void disconnect_from_device()
{
    printf("Free resources\n");
}