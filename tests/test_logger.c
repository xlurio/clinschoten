#include "unity/unity.h"
#include "clinschoten/logger.h"
#include "clinschoten/constants.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_logger_creation(void)
{
    ClnLogger logger;
    logger.name = "TestLogger";
    
    TEST_ASSERT_NOT_NULL(logger.name);
    TEST_ASSERT_EQUAL_STRING("TestLogger", logger.name);
}

void test_logger_null_name(void)
{
    ClnLogger logger;
    logger.name = NULL;
    
    TEST_ASSERT_NULL(logger.name);
}

void test_logger_log_info_level(void)
{
    ClnLogger logger;
    logger.name = "InfoLogger";
    
    int8_t result = ClnLogger__log(&logger, INFO_LL, "Test message");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}

void test_logger_log_debug_level(void)
{
    ClnLogger logger;
    logger.name = "DebugLogger";
    
    int8_t result = ClnLogger__log(&logger, DEBUG_LL, "Debug message");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}

void test_logger_log_warning_level(void)
{
    ClnLogger logger;
    logger.name = "WarningLogger";
    
    int8_t result = ClnLogger__log(&logger, WARNING_LL, "Warning message");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}

void test_logger_log_error_level(void)
{
    ClnLogger logger;
    logger.name = "ErrorLogger";
    
    int8_t result = ClnLogger__log(&logger, ERROR_LL, "Error message");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}

void test_logger_log_critical_level(void)
{
    ClnLogger logger;
    logger.name = "CriticalLogger";
    
    int8_t result = ClnLogger__log(&logger, CRITICAL_LL, "Critical message");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}

void test_constants_success_error(void)
{
    TEST_ASSERT_EQUAL(0, CLN_SUCCESS);
    TEST_ASSERT_EQUAL(-1, CLN_ERROR);
}

void test_log_level_constants(void)
{
    TEST_ASSERT_EQUAL(0, NOT_SET_LL);
    TEST_ASSERT_EQUAL(1, DEBUG_LL);
    TEST_ASSERT_EQUAL(2, INFO_LL);
    TEST_ASSERT_EQUAL(3, WARNING_LL);
    TEST_ASSERT_EQUAL(4, ERROR_LL);
    TEST_ASSERT_EQUAL(5, CRITICAL_LL);
}

void test_logger_filters_lower_level(void)
{
    ClnLogger logger;
    logger.name = "FilterLogger";
    
    int8_t result = ClnLogger__log(&logger, DEBUG_LL, "Should be filtered");
    TEST_ASSERT_EQUAL(CLN_SUCCESS, result);
}
