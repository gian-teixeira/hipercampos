#include "timec.h"

// Armazena uma diferença entre duas estruturas de tempo em uma 
// terceira estrutura e a retorna
struct timeval time_diff(struct timeval begin, struct timeval end){
    struct timeval diff;
        diff.tv_sec = end.tv_sec - begin.tv_sec;
        diff.tv_usec = end.tv_usec - begin.tv_usec;
    return diff;
}

float get_milliseconds(struct timeval time) {
    float milliseconds = time.tv_sec * 1000 + time.tv_usec * 0.001;
    return milliseconds;
}

TimeSpecs create_time_specs() {
    TimeSpecs timeSpecs = (TimeSpecs)malloc(sizeof(struct TimeSpecs));
    *timeSpecs = (struct TimeSpecs){0, 0, 0, 0, 0, 0, 0};
    return timeSpecs;
}

// Começa uma nova contagem, armazenando-a na estrutura de especificação
// de tempo
void time_count(TimeSpecs specs) {
    if(specs == NULL) return;

    gettimeofday(&specs->dayTimeBegin, NULL);
    getrusage(RUSAGE_SELF, &specs->resourceTimeBegin);
}

// Finaliza a contagem de tempo atual da estrutura especificada e
// soma o novo valor com a contagem já presente na estrutura
void stop_time_count(TimeSpecs specs) {
    if(specs == NULL) return;
    
    gettimeofday(&specs->dayTimeEnd, NULL);
    getrusage(RUSAGE_SELF, &specs->resourceTimeEnd);

    struct timeval dayTimeDiff = time_diff(specs->dayTimeBegin, specs->dayTimeEnd);
    struct timeval userTimeDiff = time_diff(specs->resourceTimeBegin.ru_utime, specs->resourceTimeEnd.ru_utime);
    struct timeval systemTimeDiff = time_diff(specs->resourceTimeBegin.ru_stime, specs->resourceTimeEnd.ru_stime);

    specs->dayTime.tv_sec += dayTimeDiff.tv_sec;
    specs->dayTime.tv_usec += dayTimeDiff.tv_usec;
    specs->userTime.tv_sec += userTimeDiff.tv_sec;
    specs->userTime.tv_usec += userTimeDiff.tv_usec;
    specs->systemTime.tv_sec += systemTimeDiff.tv_sec;
    specs->systemTime.tv_usec += systemTimeDiff.tv_usec;
}

// Zera os valores de tempo armazenados em uma estrutura
void reset_time_count(TimeSpecs specs) {
    if(specs == NULL) return;

    specs->systemTime = (struct timeval){0, 0};
    specs->userTime = (struct timeval){0, 0};
    specs->dayTime = (struct timeval){0, 0};
}

void erase_time_specs(TimeSpecs specs) {
    if(specs == NULL) return;
    free(specs);
}