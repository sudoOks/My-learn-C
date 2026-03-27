/*    Задача: Сортировка пузырьком
 *
 * Ввод: 10 целых чисел.
 * Вывод: отсортированный массив (по возрастанию).
 * В случае некорректного ввода необходимо выводить "n/a".
 */

#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int data[NMAX];
    int f = input(data);
    if (f != -1) {
        sort(data);
        output(data);
    }

    return 0;
}

int input(int *a) {
    int f = 0;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            f = -1;
        }
    }
    if (f == -1) {
        printf("n/a\n");
    }
    return f;
}

void sort(int *a) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < (NMAX - i - 1); j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", a[i]);
    }
}

