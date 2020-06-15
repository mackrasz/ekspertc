#include <stdlib.h>

int compare(void* a, void* b)
{
    int a_ = *(int*)a;
    int b_ = *(int*)b;

    return (b_%2) - (a_%2);
}

int main()
{
    int data[]={4, 1, 5, 7, 3, 2, 10};

    qsort(data, 7, sizeof(int), compare);

    return 0;
}