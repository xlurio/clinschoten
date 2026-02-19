#include "ccauchy.h"
#include <stdio.h>

extern void test_logger_creation(void);
extern void test_logger_null_name(void);
extern void test_logger_log_info_level(void);
extern void test_logger_log_debug_level(void);
extern void test_logger_log_warning_level(void);
extern void test_logger_log_error_level(void);
extern void test_logger_log_critical_level(void);
extern void test_constants_success_error(void);
extern void test_log_level_constants(void);
extern void test_logger_filters_lower_level(void);

int main(void)
{
    printf("\n=== Running clinschoten tests ===\n\n");
    
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
    
    printf("\n=== Test Summary ===\n");
    printf("%d/%d tests passed\n\n", tests_passed, tests_run);
    
    return (tests_passed == tests_run) ? 0 : 1;
}
