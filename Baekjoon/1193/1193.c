#include <stdio.h>
int main(void) {
    long int N = 0;
    scanf("%ld", &N);
    long int i =0;
    for (i = 1; N - i > 0; i++)
        N -= i;
    if (i % 2) {
        printf("%ld/%ld", i + 1 - N, N);
    } else {
        printf("%ld/%ld", N, i + 1 - N);
    }
    return 0;
}