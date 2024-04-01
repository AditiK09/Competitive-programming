#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void print_alt_primes(int N) {
    int count = 0;
    int num = 2;

    while (count < N) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
            num += 2;
        } else {
            num++;
        }
    }
}

int main() {
    int N;

    scanf("%d", &N);

    print_alt_primes(N);

    return 0;
}
