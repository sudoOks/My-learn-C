// Приветствие
// Пример использования - в терминал вписать:
// 1. gcc Hello.c -o Hello
// 2. ./Hello

#include <stdio.h>

int main() {
    char name[100];

    scanf("%99s", name);

    printf("Hello, %s!\n", name);

    return 0;
}
