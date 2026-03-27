#include "my_string.h"

unsigned long my_strlen(const char *str) {
    unsigned long len;
    if (str == 0) {
        len = 0;
    } else {
        len = 0;
        while (str[len] != '\0') {
            len++;
        }
    }
    return len;
}

int my_strcmp(const char *str1, const char *str2) {
    int f;
    if (str1 == 0 && str2 == 0) {
        f = 0;
    } else {
        while (*str1 != '\0' && *str2 != '\0') {
            if (*str1 != *str2) {
                f = (*(unsigned char *)str1 - *(unsigned char *)str2);
                break;
            } else {
                ++str1;
                ++str2;
            }
        }
    }
    f = (*(unsigned char *)str1 - *(unsigned char *)str2);
    return f;
}

char *my_strcpy(char *dest, const char *src) {
    char *ret = dest;
    if (dest == 0 || src == 0) {
        ;
    } else {
        while ((*dest++ = *src++) != '\0');
    }
    return ret;
}

char *my_strcat(char *dest, const char *src) {
    char *ret = dest;
    if (dest == 0 || src == 0) {
        ;
    } else {
        while (*dest != '\0') {
            dest++;
        }
        while ((*dest++ = *src++) != '\0');
    }
    return ret;
}
