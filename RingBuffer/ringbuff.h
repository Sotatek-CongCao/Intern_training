#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#define RINGBUFFER_MAX_SIZE 1024

void ringbuffer_init(int size);

int ringbuffer_add(int value);

int ringbuffer_remove(int *value);

int ringbuffer_is_empty(void);

int ringbuffer_is_full(void);

int ringbuffer_size(void);

#endif