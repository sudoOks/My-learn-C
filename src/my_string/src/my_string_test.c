#include "my_string.h"

#include <stdio.h>

void my_strlen_test(void);
void my_strcmp_test(void);
void my_strcpy_test(void);
void my_strcat_test(void);

int main() {
    #ifndef STRLEN_TEST
    my_strlen_test();
    #endif

    #ifndef STRCMP_TEST
    my_strcmp_test();
    #endif

    #ifndef STRCPY_TEST
    my_strcpy_test();
    #endif

    #ifndef STRCAT_TEST
    my_strcat_test();
    #endif

    return 0;
}
void my_strlen_test(void) {
    const char *input;
    unsigned long expected, result;
    // Нормальное значение
    input = "Hello, world!";
    expected = 13;
    result = my_strlen(input);
    printf("my_strlen(\"%s\") = %lu, ожидается = %lu → %s\n", input, result, expected,
           (result == expected) ? "SUCCESS" : "FAIL");
    // Пустая строка (краевое значение)
    input = "";
    expected = 0;
    result = my_strlen(input);
    printf("my_strlen(\"%s\") = %lu, ожидается = %lu → %s\n", input, result, expected,
           (result == expected) ? "SUCCESS" : "FAIL");
    // Строка с одним символом (краевое значение)
    input = "A";
    expected = 1;
    result = my_strlen(input);
    printf("my_strlen(\"%s\") = %lu, ожидается = %lu → %s\n", input, result, expected,
           (result == expected) ? "SUCCESS" : "FAIL");
    // Ноль (ненормальное значение)
    input = 0;
    expected = 0;
    result = my_strlen(input);
    printf("my_strlen(NULL) = %lu, ожидается = %lu → %s\n", result, expected,
           (result == expected) ? "SUCCESS" : "FAIL");
}

void my_strcmp_test(void) {
    const char *a;
    const char *b;
    // Одинаковые строки
    a = "abc";
    b = "abc";
    int r1 = my_strcmp(a, b);
    printf("my_strcmp(\"%s\", \"%s\") = %d, ожидается = 0 → %s\n", a, b, r1, (r1 == 0) ? "SUCCESS" : "FAIL");
    // Первая строка меньше
    a = "ab";
    b = "ac";
    int r2 = my_strcmp(a, b);
    printf("my_strcmp(\"%s\", \"%s\") = %d, ожидается < 0 → %s\n", a, b, r2, (r2 < 0) ? "SUCCESS" : "FAIL");
    // Вторая строка меньше
    a = "8";
    b = "0";
    int r3 = my_strcmp(a, b);
    printf("my_strcmp(\"%s\", \"%s\") = %d, ожидается > 0 → %s\n", a, b, r3, (r3 > 0) ? "SUCCESS" : "FAIL");
}

void my_strcpy_test(void) {
    char data[100];
    char *result;
    // Нормальная строка
    result = my_strcpy(data, "Hello");
    printf("my_strcpy(data, \"Hello\") → назначено = \"%s\", возвращено = %s → %s\n", data,
           (result == data) ? "data" : "other",
           (my_strcmp(data, "Hello") == 0 && result == data) ? "SUCCESS" : "FAIL");
    // Пустая строка (краевое значение)
    result = my_strcpy(data, "");
    printf("my_strcpy(data, \"\") → назначено = \"%s\", возвращено = %s → %s\n", data,
           (result == data) ? "data" : "other",
           (my_strcmp(data, "") == 0 && result == data) ? "SUCCESS" : "FAIL");
    // Один символ
    result = my_strcpy(data, "A");
    printf("my_strcpy(data, \"A\") → назначено = \"%s\", возвращено = %s → %s\n", data,
           (result == data) ? "data" : "other",
           (my_strcmp(data, "A") == 0 && result == data) ? "SUCCESS" : "FAIL");
    // 0 в src (ненормальное значение)
    result = my_strcpy(data, 0);
    printf("my_strcpy(data, 0) → возвращено = %s → %s\n", (result == data) ? "data" : "other",
           (result == data) ? "SUCCESS" : "FAIL");
}

void my_strcat_test(void) {
    char data[100];
    char *result;
    // Нормальные строки
    my_strcpy(data, "Hello, ");
    result = my_strcat(data, "world!");
    printf("my_strcat(\"Hello, \", \"world!\") → \"%s\" → %s\n", data,
           (my_strcmp(data, "Hello, world!") == 0 && result == data) ? "SUCCESS" : "FAIL");
    // пустая строка в src (краевое значение)
    my_strcpy(data, "Test");
    result = my_strcat(data, "");
    printf("my_strcat(\"Test\", \"\") → \"%s\" → %s\n", data,
           (my_strcmp(data, "Test") == 0 && result == data) ? "SUCCESS" : "FAIL");
    // 0 в src (ненормальное значение)
    my_strcpy(data, "OK");
    result = my_strcat(data, 0);
    printf("my_strcat(\"OK\", 0) → возвращено = %s → %s\n", (result == data) ? "data" : "other",
           (result == data) ? "SUCCESS" : "FAIL");
}
