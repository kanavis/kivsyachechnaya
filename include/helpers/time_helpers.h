/* Time helpers header */
#pragma once

#include <cstdint>
#include <string>
#include <sys/time.h>
#include <time.h>


int64_t utimestamp();
int32_t timestamp();

/* Get formatted time */
std::string strftime_str(const char * format, struct tm* tm_info);
std::string strftime_str(const char * format, struct timeval tv);
std::string strftime_str(const char * format);
