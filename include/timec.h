#ifndef TIMEC
#define TIMEC

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>

typedef struct TimeSpecs {
    struct timeval systemTime;
    struct timeval userTime;
    struct timeval dayTime;
    struct rusage resourceTimeBegin;
    struct rusage resourceTimeEnd;
    struct timeval dayTimeBegin;
    struct timeval dayTimeEnd;
} *TimeSpecs;

TimeSpecs create_time_specs();
void time_count(TimeSpecs specs);
void stop_time_count(TimeSpecs specs);
void erase_time_specs(TimeSpecs specs);
void reset_time_count(TimeSpecs specs);
struct timeval time_diff(struct timeval begin, struct timeval end);
float get_milliseconds(struct timeval time);

#endif