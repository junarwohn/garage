#include <stdio.h>
int main(void) {
    long long int N = 0;
    long long int comb = 1;
    scanf("%d", &N);
    long long int i;
    for (i = 1; comb < N; i++) {
        comb += 6 * i;
    }
    printf("%lld", i);
    return 0;
}