#include <stdio.h>

typedef void action(); 

void hello()
{
    printf("Hello\n");
}

void world()
{
    printf("world\n");
}

void calltwice(action* fun)
{
    fun();
    fun();
}

int main()
{
    calltwice(&world);
    return 0;
}