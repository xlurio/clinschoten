#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <clinschoten/constants.h>
#include <clinschoten/logger.h>

int8_t getVerboseLogLevel(uint8_t logLevel, char **result)
{
    size_t bufferSize = 9 * sizeof(char);
    *result = malloc(bufferSize);

    if (*result == NULL)
    {
        return CLN_ERROR;
    }

    memset(*result, 0, bufferSize);

    switch (logLevel)
    {
    case CLN_NOT_SET_LL:
        strcpy(*result, "NOT SET");
        return CLN_SUCCESS;
    case CLN_DEBUG_LL:
        strcpy(*result, "DEBUG");
        return CLN_SUCCESS;
    case CLN_INFO_LL:
        strcpy(*result, "INFO");
        return CLN_SUCCESS;
    case CLN_WARNING_LL:
        strcpy(*result, "WARNING");
        return CLN_SUCCESS;
    case CLN_ERROR_LL:
        strcpy(*result, "ERROR");
        return CLN_SUCCESS;
    case CLN_CRITICAL_LL:
        strcpy(*result, "CRITICAL");
        return CLN_SUCCESS;
    }

    free(*result);
    *result = NULL;
    return CLN_ERROR;
}

ClnLogger *ClnLogger__new(const char *name, size_t nameSize)
{
    ClnLogger *logger = malloc(sizeof(ClnLogger));

    if (logger == NULL)
    {
        fprintf(stderr, "clinschoten - CRITICAL: Unable to allocate memory for logger");
        return NULL;
    }

    logger->name = name;
    logger->nameSize = nameSize;

    return logger;
}

int8_t ClnLogger__log(ClnLogger *self,
                      uint8_t logLevel,
                      char *msg,
                      size_t msgSize,
                      ...)
{
    char *verboseLogLevel;

    if (CLN_LOG_LEVEL > logLevel)
    {
        return CLN_SUCCESS;
    }

    if (getVerboseLogLevel(logLevel, &verboseLogLevel) == CLN_ERROR)
    {
        fprintf(
            stderr,
            "clinschoten - CRITICAL: Unable to get verbose log level\n");
        return CLN_ERROR;
    }

    size_t formattedMsgLength = self->nameSize            //
                                + strlen(" - ")           //
                                + strlen(verboseLogLevel) //
                                + strlen(": ")            //
                                + msgSize                 //
                                + strlen("\n")            //
                                + 1;
    char *formattedMsg = malloc(formattedMsgLength);

    if (formattedMsg == NULL)
    {
        free(verboseLogLevel);
        return CLN_ERROR;
    }

    memset(formattedMsg, 0, formattedMsgLength);

    snprintf(
        formattedMsg,
        formattedMsgLength,
        "%s - %s: %s\n",
        self->name,
        verboseLogLevel,
        msg);

    va_list args;
    va_start(args, msgSize);
    vprintf(formattedMsg, args);
    va_end(args);

    free(verboseLogLevel);
    free(formattedMsg);

    return CLN_SUCCESS;
}

void ClnLogger__del(ClnLogger *self)
{
    free(self);
}
