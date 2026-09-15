#include <gtest/gtest.h>
extern "C"
{
#include "ringbuff.h"
}
TEST(RingBufferTest, InitEmpty)
{
    ringbuffer_init(1026);
    ringbuffer_init(5);

    EXPECT_TRUE(ringbuffer_is_empty());
    EXPECT_FALSE(ringbuffer_is_full());
    EXPECT_EQ(ringbuffer_size(), 0);
}
TEST(RingBufferTest, Add)
{
    ringbuffer_init(5);

    EXPECT_EQ(ringbuffer_add(10), 0);

    EXPECT_FALSE(ringbuffer_is_empty());
    EXPECT_EQ(ringbuffer_size(), 1);
}
TEST(RingBufferTest, Remove)
{
    ringbuffer_init(5);

    ringbuffer_add(10);

    int value;

    EXPECT_EQ(ringbuffer_remove(&value), 0);
    EXPECT_EQ(value, 10);

    EXPECT_TRUE(ringbuffer_is_empty());
}
TEST(RingBufferTest, FIFO)
{
    ringbuffer_init(5);

    ringbuffer_add(10);
    ringbuffer_add(20);
    ringbuffer_add(30);

    int value;

    ringbuffer_remove(&value);
    EXPECT_EQ(value, 10);

    ringbuffer_remove(&value);
    EXPECT_EQ(value, 20);

    ringbuffer_remove(&value);
    EXPECT_EQ(value, 30);
}
TEST(RingBufferTest, Full)
{
    ringbuffer_init(5);

    EXPECT_EQ(ringbuffer_add(1), 0);
    EXPECT_EQ(ringbuffer_add(2), 0);
    EXPECT_EQ(ringbuffer_add(3), 0);
    EXPECT_EQ(ringbuffer_add(4), 0);
    EXPECT_EQ(ringbuffer_add(5), 0);

    EXPECT_TRUE(ringbuffer_is_full());
    EXPECT_EQ(ringbuffer_size(), 5);

    EXPECT_EQ(ringbuffer_add(6), -1);
}
TEST(RingBufferTest, EmptyRemove)
{
    ringbuffer_init(5);

    int value;

    EXPECT_EQ(ringbuffer_remove(&value), -1);
    EXPECT_TRUE(ringbuffer_is_empty());
}