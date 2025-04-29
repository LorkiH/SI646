// eratosten.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int end = (int)sqrt((double)num);
    for (int i = 3; i <= end; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void sieve(int n) {
    bool* is_prime = (bool*)malloc(sizeof(bool) * (n + 1));
    if (is_prime == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_prime(num)) {
        printf("The number %d is prime.\n", num);
    } else {
        printf("The number %d is not prime.\n", num);
    }

    sieve(num);

    return EXIT_SUCCESS;
}
