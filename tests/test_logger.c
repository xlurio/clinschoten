#include "ccauchy.h"
#include "clinschoten/logger.h"
#include "clinschoten/constants.h"
#include <stdlib.h>
#include <string.h>

TEST(test_logger_creation)
{
    ClnLogger *logger = ClnLogger__new("TestLogger", strlen("TestLogger"));
    
    ASSERT_NOT_NULL(logger, "Logger should be allocated");
    ASSERT_NOT_NULL(logger->name, "logger->name");
    ASSERT_STR_EQ(logger->name, "TestLogger", "Logger name should be 'TestLogger'");
    
    ClnLogger__del(logger);
}

TEST(test_logger_null_name)
{
    ClnLogger *logger = ClnLogger__new(NULL, 0);
    
    ASSERT_NOT_NULL(logger, "Logger should be allocated even with NULL name");
    ASSERT_NULL(logger->name, "logger->name");
    
    ClnLogger__del(logger);
}

TEST(test_logger_log_info_level)
{
    ClnLogger *logger = ClnLogger__new("InfoLogger", strlen("InfoLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_INFO_LL, "Test message");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS for INFO level");
    
    ClnLogger__del(logger);
}

TEST(test_logger_log_debug_level)
{
    ClnLogger *logger = ClnLogger__new("DebugLogger", strlen("DebugLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_DEBUG_LL, "Debug message");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS for DEBUG level");
    
    ClnLogger__del(logger);
}

TEST(test_logger_log_warning_level)
{
    ClnLogger *logger = ClnLogger__new("WarningLogger", strlen("WarningLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_WARNING_LL, "Warning message");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS for WARNING level");
    
    ClnLogger__del(logger);
}

TEST(test_logger_log_error_level)
{
    ClnLogger *logger = ClnLogger__new("ErrorLogger", strlen("ErrorLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_ERROR_LL, "Error message");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS for ERROR level");
    
    ClnLogger__del(logger);
}

TEST(test_logger_log_critical_level)
{
    ClnLogger *logger = ClnLogger__new("CriticalLogger", strlen("CriticalLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_CRITICAL_LL, "Critical message");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS for CRITICAL level");
    
    ClnLogger__del(logger);
}

TEST(test_constants_success_error)
{
    ASSERT_EQ(CLN_SUCCESS, 0, "CLN_SUCCESS should equal 0");
    ASSERT_EQ(CLN_ERROR, -1, "CLN_ERROR should equal -1");
}

TEST(test_log_level_constants)
{
    ASSERT_EQ(CLN_NOT_SET_LL, 0, "CLN_NOT_SET_LL should equal 0");
    ASSERT_EQ(CLN_DEBUG_LL, 1, "CLN_DEBUG_LL should equal 1");
    ASSERT_EQ(CLN_INFO_LL, 2, "CLN_INFO_LL should equal 2");
    ASSERT_EQ(CLN_WARNING_LL, 3, "CLN_WARNING_LL should equal 3");
    ASSERT_EQ(CLN_ERROR_LL, 4, "CLN_ERROR_LL should equal 4");
    ASSERT_EQ(CLN_CRITICAL_LL, 5, "CLN_CRITICAL_LL should equal 5");
}

TEST(test_logger_filters_lower_level)
{
    ClnLogger *logger = ClnLogger__new("FilterLogger", strlen("FilterLogger"));
    
    int8_t result = ClnLogger__log(logger, CLN_DEBUG_LL, "Should be filtered");
    ASSERT_EQ(result, CLN_SUCCESS, "Logger should return CLN_SUCCESS even for filtered messages");
    
    ClnLogger__del(logger);
}
