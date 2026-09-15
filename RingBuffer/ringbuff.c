#include "ringbuff.h"

static int buffer[RINGBUFFER_MAX_SIZE];

static int head = 0;
static int tail = 0;
static int count = 0;
static int capacity = 0;

void ringbuffer_init(int size)
{
    if (size < 1 || size > RINGBUFFER_MAX_SIZE)
    {
        capacity = 0;
        head = 0;
        tail = 0;
        count = 0;
        return;
    }
    capacity = size;
    head = 0;
    tail = 0;
    count = 0;
}

int ringbuffer_add(int value)
{
    if (capacity == 0 || count == capacity)
    {
        return -1;
    }
    buffer[head] = value;
    head = (head + 1) % capacity;
    count++;
    return 0;
}

int ringbuffer_remove(int *value)
{
    if (capacity == 0 || count == 0)
    {
        return -1;
    }
    *value = buffer[tail];
    tail = (tail + 1) % capacity;
    count--;
    return 0;
}

int ringbuffer_is_empty(void)
{
    int result = (count == 0);
    return result;
}

int ringbuffer_is_full(void)
{
    int result = (capacity > 0 && count == capacity);
    return result;
}

int ringbuffer_size(void)
{
    int result = count;
    return result;
}