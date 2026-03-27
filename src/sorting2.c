/*    Задача: Сортировка с выделением памяти
 *
 * Ввод: 10 целых чисел, например:
 * 10
 * 4 3 9 0 1 2 100 2 7 -1
 * Вывод: отсортированный массив (по возрастанию).
 * В случае некорректного ввода/ ошибки необходимо выводить "n/a".
 * Память под массив выделяется динамически (при помощи функций malloc или calloc)*
 */

#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void sort(int *a, int n);
void output(const int *a, int n);

int main() {
    int n, *data;
    int f = input(&data, &n);
    if (f != -1) {
        sort(data, n);
        output(data, n);
        free(data);
    }
    return 0;
}

int input(int **a, int *n) {
    int f = 0;
    int res = scanf("%d", n);
    if (res != 1 || (*n <= 0)) {
        f = -1;
    }
    *a = (int *)malloc(*n * sizeof(int));
    if (*a == NULL) {
        f = -1;
    }
    if (f != -1) {
        for (int *p = *a; p - *a < *n; p++) {
            if (scanf("%d", p) != 1) {
                f = -1;
            }
        }
    }
    if (f == -1) {
        printf("n/a\n");
        free(*a);
    }
    return f;
}

void sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void output(const int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
