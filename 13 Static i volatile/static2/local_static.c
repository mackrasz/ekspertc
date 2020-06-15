#include <stdio.h>

int add(int num1)
{
    int num2 = 1;
    num2 += num1;
    return num2;
}

int main()
{
    int num1 = 1;
    num1 = add(num1);
    num1 = add(num1);

    printf("%d", num1);

    return  0;
}