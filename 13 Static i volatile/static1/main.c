#include <string.h>
#include "lib.h"

char dev_id[4];

int main()
{
    initialize_device();
    connect_to_device();
    strcpy(dev_id, "DEF");
    disconnect_from_device();

    return 0;
}