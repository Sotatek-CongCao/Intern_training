#include <stdio.h>
#include "ringbuff.h"

int main()
{
    ringbuffer_init(5);
    ringbuffer_add(100);
    ringbuffer_add(20);
    int value;
    ringbuffer_remove(&value);
    printf("%d", value);
}