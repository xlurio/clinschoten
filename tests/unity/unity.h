#ifndef UNITY_FRAMEWORK_H
#define UNITY_FRAMEWORK_H

#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define UNITY_OUTPUT_CHAR(a)    putchar(a)
#define UNITY_OUTPUT_FLUSH()    fflush(stdout)
#define UNITY_OUTPUT_START()    
#define UNITY_OUTPUT_COMPLETE()

struct UNITY_STORAGE_T
{
    uint16_t NumberOfTests;
    uint16_t TestFailures;
    uint16_t TestIgnores;
    uint8_t CurrentTestFailed;
    uint8_t CurrentTestIgnored;
    jmp_buf AbortFrame;
};

extern struct UNITY_STORAGE_T Unity;

void UnityBegin(const char* filename);
int UnityEnd(void);
void UnityConcludeTest(void);
void UnityDefaultTestRun(void (*Func)(void), const char* FuncName, const int FuncLineNum);

void UnityAssertEqualNumber(const int expected, const int actual, const char* msg, const unsigned short lineNumber);
void UnityAssertEqualString(const char* expected, const char* actual, const char* msg, const unsigned short lineNumber);
void UnityAssertNotNull(const void* pointer, const char* msg, const unsigned short lineNumber);
void UnityAssertNull(const void* pointer, const char* msg, const unsigned short lineNumber);
void UnityFail(const char* msg, const int line);

#define TEST_ASSERT_EQUAL(expected, actual) \
    UnityAssertEqualNumber((int)(expected), (int)(actual), NULL, __LINE__)

#define TEST_ASSERT_EQUAL_MESSAGE(expected, actual, message) \
    UnityAssertEqualNumber((int)(expected), (int)(actual), (message), __LINE__)

#define TEST_ASSERT_EQUAL_STRING(expected, actual) \
    UnityAssertEqualString((expected), (actual), NULL, __LINE__)

#define TEST_ASSERT_NOT_NULL(pointer) \
    UnityAssertNotNull((pointer), NULL, __LINE__)

#define TEST_ASSERT_NULL(pointer) \
    UnityAssertNull((pointer), NULL, __LINE__)

#define TEST_FAIL(message) \
    UnityFail((message), __LINE__)

#define TEST_ASSERT_TRUE(condition) \
    UnityAssertEqualNumber(1, (condition) ? 1 : 0, NULL, __LINE__)

#define TEST_ASSERT_FALSE(condition) \
    UnityAssertEqualNumber(0, (condition) ? 1 : 0, NULL, __LINE__)

#define RUN_TEST(func) UnityDefaultTestRun(func, #func, __LINE__)

#ifdef __cplusplus
}
#endif

#endif
