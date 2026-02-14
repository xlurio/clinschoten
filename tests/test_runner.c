#include "unity/unity.h"
#include <stdio.h>

void test_logger_creation(void);
void test_logger_null_name(void);
void test_logger_log_info_level(void);
void test_logger_log_debug_level(void);
void test_logger_log_warning_level(void);
void test_logger_log_error_level(void);
void test_logger_log_critical_level(void);
void test_constants_success_error(void);
void test_log_level_constants(void);
void test_logger_filters_lower_level(void);

void setUp(void);
void tearDown(void);

int main(void)
{
    UnityBegin("test_logger.c");
    
    RUN_TEST(test_logger_creation);
    RUN_TEST(test_logger_null_name);
    RUN_TEST(test_logger_log_info_level);
    RUN_TEST(test_logger_log_debug_level);
    RUN_TEST(test_logger_log_warning_level);
    RUN_TEST(test_logger_log_error_level);
    RUN_TEST(test_logger_log_critical_level);
    RUN_TEST(test_constants_success_error);
    RUN_TEST(test_log_level_constants);
    RUN_TEST(test_logger_filters_lower_level);
    
    return UnityEnd();
}
