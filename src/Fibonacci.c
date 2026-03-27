/*    Задача: Число Фибоначчи
 *
 * Программа рассчитывает и выводит на экран n-ое число Фибоначчи.
 * В случае ошибки выводить "n/a".
 */

#include <stdio.h>

int fib(int n);

int main() {
    float nf;
    scanf("%f", &nf);
    int n = nf;
    if (n > 47 ) {
        printf("переполнение\n");
        return 0;
    }
    else if ((n != nf) || (n <= 0)) {
        printf("n/a\n");
        return 0;
    }
    printf("%d\n", fib(n));
    return 0;
}

int fib(int n) {
    int fib_n;
    if (n == 1 || n == 2)
        fib_n = 1;
    else
        fib_n = fib(n - 1) + fib(n - 2);
    return fib_n;
}
