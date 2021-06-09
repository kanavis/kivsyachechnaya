/* Time helpers */

#include <cstdint>
#include <string>
#include <sys/time.h>
#include <time.h>

#include "helpers/time_helpers.h"
#include "kivsyachechnaya.h"


int64_t utimestamp() {
    struct timeval tv_now;

    gettimeofday(&tv_now, NULL);

    return (int64_t)tv_now.tv_sec * 1000000L + (int64_t)tv_now.tv_usec;
}

int32_t timestamp() {
    return (unsigned)time(NULL);
}


/* Get formatted time */
std::string strftime_str(const char * format, struct tm* tm_info) {
    char buffer[64];

    strftime(buffer, 64, format, tm_info);

    return std::string(buffer);
}

std::string strftime_str(const char * format, struct timeval tv) {
    struct tm* tm_info;

    tm_info = localtime(&tv.tv_sec);

    return strftime_str(format, tm_info);
}

std::string strftime_str(const char * format) {
    struct timeval tv;

    gettimeofday(&tv, NULL);

    return strftime_str(format, tv);
}
