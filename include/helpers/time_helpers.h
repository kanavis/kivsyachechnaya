/* Time helpers header */
#include <cstdint>
#include <sys/time.h>
#include <time.h>


int64_t utimestamp() {
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    return (int64_t)tv_now.tv_sec * 1000000L + (int64_t)tv_now.tv_usec;
}

int32_t timestamp() {
    return (unsigned)time(NULL);
}
