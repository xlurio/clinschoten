#ifndef CLINSCHOTEN_CONSTANTS_H
#define CLINSCHOTEN_CONSTANTS_H

#define CLN_ERROR -1
#define CLN_SUCCESS 0

// Log levels
#define NOT_SET_LL 0
#define DEBUG_LL 1
#define INFO_LL 2
#define WARNING_LL 3
#define ERROR_LL 4
#define CRITICAL_LL 5

#ifndef CLN_LOG_LEVEL
#define CLN_LOG_LEVEL INFO_LL
#endif

#endif
