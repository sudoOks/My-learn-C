/*    Задача: Работа с матрицей
 *
 * Ввод: способ выделения памяти(статический = 1, динамический = 2), размер матрицы, данные матрицы, например:
 * 1
 * 3 3
 * 1 2 1
 * -5 9 101
 * 0 3 11
 * Вывод: сам массив, массив максимумов строк, массив минимумов столбцов.
 * В случае некорректного ввода/ ошибки необходимо выводить "n/a".
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int static_m(int str, int col);
int dyn_matrix(int str, int col);
int dyn_matrix_2(int str, int col);
int dyn_matrix_3(int str, int col);

int main() {
    int f = 0;
    int a = 1, b = 2;
    int str, col;

    int menu;
    scanf("%d", &menu);
    if ((menu < a || menu > b) && menu != 1) {
        f = -1;
    } else if ((scanf("%d %d", &str, &col) != 2) && (str <= 0 || col <= 0 || str > SIZE || col > SIZE)) {
        f = -1;
    }

    else if (menu == a) {
        f = static_m(str, col);
    } else if (menu == b) {
        f = dyn_matrix(str, col);
    }

    if (f == -1) {
        printf("n/a");
    }
    return 0;
}

int static_m(int str, int col) {
    int f = 0;
    int a[str][col];
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                f = -1;
                break;
            }
        }
    }
    if (f != -1) {
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d", a[i][j]);
                if (j != col - 1) {
                    printf(" ");
                }
            }
            if (i != str - 1) {
                printf("\n");
            }
        }
    }
    return f;
}

int dyn_matrix(int str, int col) {
    int f = 0;
    int** a = malloc(str * sizeof(int*));
    if (a == NULL) {
        f = -1;
    }
    if (f != -1) {
        for (int i = 0; i < str; i++) {
            a[i] = malloc(col * sizeof(int*));
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < col; j++) {
                if (scanf("%d", &a[i][j]) != 1) {
                    f = -1;
                    break;
                }
            }
        }
    }
    if (f != -1) {
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d", a[i][j]);
                if (j != col - 1) {
                    printf(" ");
                }
            }
            if (i != str - 1) {
                printf("\n");
            }
        }
        for (int i = 0; i < str; i++) {
            free(a[i]);
        }
    }
    free(a);
    return f;
}
