/*    Задача: Набор статистических метрик
 *
 * Ввод: значение количества чисел (до 10), а затем сами числа.
 * Вывод: исходные введенные числа, на новой строке набор статистических метрик - max и min, математическое ожидание и дисперсия.
 * В случае некорректного ввода необходимо выводить "n/a".
 * Вещественные числа с точностью 4 знаков после запятой.
 */

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int f = input(data, &n);
    if (f != -1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }

    return 0;
}

int input(int *a, int *n) {
    int res = scanf("%d", n);
    int f = 0;
    if (res != 1 || (*n <= 0 || *n > NMAX)) {
        f = -1;
    }
    if (f != -1) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                f = -1;
            }
        }
    }
    if (f == -1) {
        printf("n/a\n");
    }
    return f;
}

void output(int *a, int n) {
    printf("Введенные числа: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] >= max) max = a[i];
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] <= min) min = a[i];
    }
    return min;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return ((double)sum / n);
}

double variance(int *a, int n) {
    double sred = mean(a, n);
    double D = 0;
    for (int i = 0; i < n; i++) {
        D += ((a[i] - sred) * (a[i] - sred));
    }
    return (D / n);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("max: %d, min: %d, mean: %.4lf, variance: %.4lf\n", max_v, min_v, mean_v, variance_v);
}

