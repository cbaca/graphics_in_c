#include "test.h"
void print_speed(const char *msg, const size_t len, const testtime_t clk)
{
    printf("%s speed:   %.4lf MB/s\n", msg,
        (double)(10000000 * sizeof(float) * len / (size_t)clk * CLOCKS_PER_SEC / 1000000));
}

testtime_t get_start_time(void)
{
    return (testtime_t)clock();
}

testtime_t get_end_time(const testtime_t start)
{
    return clock() - (clock_t)start;
}
