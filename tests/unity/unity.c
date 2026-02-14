#include "unity.h"
#include <stdio.h>
#include <string.h>

struct UNITY_STORAGE_T Unity;

void UnityBegin(const char* filename)
{
    Unity.NumberOfTests = 0;
    Unity.TestFailures = 0;
    Unity.TestIgnores = 0;
    Unity.CurrentTestFailed = 0;
    Unity.CurrentTestIgnored = 0;
    
    printf("%s:1:test\n", filename);
}

int UnityEnd(void)
{
    printf("\n-----------------------\n");
    printf("%d Tests %d Failures %d Ignored\n",
           Unity.NumberOfTests,
           Unity.TestFailures,
           Unity.TestIgnores);
    
    if (Unity.TestFailures == 0)
    {
        printf("OK\n");
        return 0;
    }
    else
    {
        printf("FAIL\n");
        return 1;
    }
}

void UnityConcludeTest(void)
{
    if (Unity.CurrentTestIgnored)
    {
        Unity.TestIgnores++;
    }
    else if (Unity.CurrentTestFailed)
    {
        Unity.TestFailures++;
    }
    
    Unity.NumberOfTests++;
    Unity.CurrentTestFailed = 0;
    Unity.CurrentTestIgnored = 0;
}

void UnityDefaultTestRun(void (*Func)(void), const char* FuncName, const int FuncLineNum)
{
    (void)FuncLineNum;
    
    if (Unity.CurrentTestFailed || Unity.CurrentTestIgnored)
    {
        return;
    }
    
    printf("\nTEST(%s)", FuncName);
    
    if (setjmp(Unity.AbortFrame) == 0)
    {
        Func();
    }
    
    UnityConcludeTest();
}

void UnityAssertEqualNumber(const int expected, const int actual, const char* msg, const unsigned short lineNumber)
{
    if (expected != actual)
    {
        Unity.CurrentTestFailed = 1;
        printf("\n%s:%d:FAIL: Expected %d Was %d", 
               msg ? msg : "Assertion Failed",
               lineNumber,
               expected,
               actual);
        longjmp(Unity.AbortFrame, 1);
    }
}

void UnityAssertEqualString(const char* expected, const char* actual, const char* msg, const unsigned short lineNumber)
{
    if ((expected == NULL && actual != NULL) ||
        (expected != NULL && actual == NULL) ||
        (expected != NULL && actual != NULL && strcmp(expected, actual) != 0))
    {
        Unity.CurrentTestFailed = 1;
        printf("\n%s:%d:FAIL: Expected '%s' Was '%s'",
               msg ? msg : "Assertion Failed",
               lineNumber,
               expected ? expected : "NULL",
               actual ? actual : "NULL");
        longjmp(Unity.AbortFrame, 1);
    }
}

void UnityAssertNotNull(const void* pointer, const char* msg, const unsigned short lineNumber)
{
    if (pointer == NULL)
    {
        Unity.CurrentTestFailed = 1;
        printf("\n%s:%d:FAIL: Expected pointer to be non-NULL",
               msg ? msg : "Assertion Failed",
               lineNumber);
        longjmp(Unity.AbortFrame, 1);
    }
}

void UnityAssertNull(const void* pointer, const char* msg, const unsigned short lineNumber)
{
    if (pointer != NULL)
    {
        Unity.CurrentTestFailed = 1;
        printf("\n%s:%d:FAIL: Expected pointer to be NULL",
               msg ? msg : "Assertion Failed",
               lineNumber);
        longjmp(Unity.AbortFrame, 1);
    }
}

void UnityFail(const char* msg, const int line)
{
    Unity.CurrentTestFailed = 1;
    printf("\n%s:%d:FAIL: %s",
           msg ? msg : "Test Failed",
           line,
           msg ? msg : "");
    longjmp(Unity.AbortFrame, 1);
}
