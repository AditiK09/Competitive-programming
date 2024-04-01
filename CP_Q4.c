#include <stdio.h>

int calculate_mod(int a, int b, int m) {
    if (b == 0)
        return 1;

    int result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 != 0) {
            result = (result * a) % m;
        }
        b = b / 2;
        a = (a * a) % m;
    }

    return result;
}

int main() {
    int a, b, m;
    scanf("%d %d %d", &a, &b, &m);

    int result = calculate_mod(a, b, m);
    printf("%d\n", a, b, m, result);

    return 0;
}
