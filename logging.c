// logging.c
#include "logging.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void sentinel_log(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("[%04d-%02d-%02d %02d:%02d:%02d] ",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday,
           t->tm_hour, t->tm_min, t->tm_sec);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}
