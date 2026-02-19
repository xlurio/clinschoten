#ifndef CLINSCHOTEN_LOGGER_H
#define CLINSCHOTEN_LOGGER_H

#include <stdint.h>

typedef struct ClnLogger
{
    const char *name;
    size_t nameSize;
} ClnLogger;

ClnLogger *ClnLogger__new(const char *name, size_t nameSize);
int8_t ClnLogger__log(ClnLogger *self,
                      uint8_t logLevel,
                      char *msg,
                      size_t msgSize,
                      ...);
void ClnLogger__del(ClnLogger *self);

#endif
