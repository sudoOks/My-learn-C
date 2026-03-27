/*    Задача: Наибольший простой делитель
 *
 * Программа находит и выводит наибольший простой делитель числа.
 * Вывести "n/a", если делитель не найден / некорректный ввод.
 */

#include <stdio.h>
#include <stdlib.h>

int del(int a);
int prost(int num);

int main() {
    float n1;
    scanf("%f", &n1);
    int a = n1;
    if (n1 != a || a == 0 || a == 1) {
        printf("n/a\n");
        return 0;
    }

    if (a < 0) {
        a = abs(a);
        printf("%d\n", del(a));
        return 0;
    }

    printf("%d\n", del(a));

    return 0;
}

int del(int a) {
    int x;
    int res = a;
    for (int i = 2; i < a; i++) {
        x = a;
        while (x >= i) {
            x = x - i;
        }
        if (x == 0 && (prost(i) == 1)) {
            res = i;
        }
    }
    return res;
}

int prost(int i) {
    int f = 1;
    for (int j = 2; (j * j) <= i; j++) {
        int tmp = i;
        while (tmp >= j) {
            tmp = tmp - j;
        }
        if (tmp == 0) {
            f = 0;
            break;
        }
    }
    return f;
}
