#ifndef CLINSCHOTEN_LOGGER_H
#define CLINSCHOTEN_LOGGER_H

#include <stdint.h>

typedef struct ClnLogger
{
    char *name;
} ClnLogger;

int8_t ClnLogger__log(ClnLogger *self, uint8_t logLevel, char *msg, ...);

#endif
