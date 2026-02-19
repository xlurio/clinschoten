#ifndef CLINSCHOTEN_CONSTANTS_H
#define CLINSCHOTEN_CONSTANTS_H

#define CLN_ERROR -1
#define CLN_SUCCESS 0

// Log levels
#define CLN_NOT_SET_LL 0
#define CLN_DEBUG_LL 1
#define CLN_INFO_LL 2
#define CLN_WARNING_LL 3
#define CLN_ERROR_LL 4
#define CLN_CRITICAL_LL 5

#ifndef CLN_LOG_LEVEL
#define CLN_LOG_LEVEL CLN_INFO_LL
#endif

#endif
