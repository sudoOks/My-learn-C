/*    Задача: Циклический сдвиг чисел
 *
 * Ввод: количество чисел, массив целых чисел, величина сдвига, например:
 * 10
 * 4 3 9 0 1 2 0 2 7 -1
 * 2
 * Вывод: Измененный массив (после сдвига).
 * В случае некорректного ввода необходимо выводить "n/a".
 * Максимальный размер: 10 чисел.
 * Положительное число - сдвиг влево, отрицательное - вправо.
 */

#include <stdio.h>
#define NMAX 10

int input(int *A, int *n, int *c);
void swap(int *A, int n, int c);
void output(int *A);

int main() {
    int n, data[NMAX], c;
    int f = input(data, &n, &c);
    if (f != -1) {
        swap(data, n, c);
        output(data);
    }
    return 0;
}

int input(int *A, int *n, int *c) {
    int res = scanf("%d", n);
    int f = 0;
    if (res != 1 || (*n <= 0 || *n > NMAX)) {
        f = -1;
    }
    if (f != -1) {
        for (int *p = A; p - A < *n; p++) {
            if (scanf("%d", p) != 1) {
                f = -1;
            }
        }
    }
    if (scanf("%d", c) != 1) {
        f = -1;
    }
    if (f == -1) {
        printf("n/a\n");
    }
    return f;
}

void swap(int *A, int n, int c) {
    if (c > 0) {
        for (int j = 0; j < c; j++) {
            int tmp = A[0];
            for (int i = 0; i < (n - 1); i++) {
                A[i] = A[i + 1];
            }
            A[(n - 1)] = tmp;
        }
    } else if (c < 0) {
        int c_new = n + c;
        for (int j = 0; j < c_new; j++) {
            int tmp = A[0];
            for (int i = 0; i < (n - 1); i++) {
                A[i] = A[i + 1];
            }
            A[(n - 1)] = tmp;
        }
    }
}

void output(int *A) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", A[i]);
    }
}
