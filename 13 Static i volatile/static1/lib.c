#include "lib.h"
#include <stdio.h>
#include <string.h>

static char dev_id[4];

void initialize_device()
{
    strcpy(dev_id, "ABC");
}

void connect_to_device()
{
    printf("Connected to: %s\n", dev_id);
}

void disconnect_from_device()
{
    printf("Disconnected from: %s\n", dev_id);
}