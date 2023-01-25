#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    while (n) {
        int * prime_num_list = (int *)malloc(sizeof(int) * (2 * n + 1));
        prime_num_list[1] = 1;
        for (int i = 2; i <= 2 * n; i++)
            prime_num_list[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (prime_num_list[i])
                continue;
            for (int j = 2; (j * i) <= (2 * n); j++)
                prime_num_list[i * j]++;
        }
        int total = 0;
        for (int i = n + 1; i <= 2*n; i++) {
            if (!prime_num_list[i])
                total++;
        }
        printf("%d\n", total);
        free(prime_num_list);
        scanf("%d", &n);
    }
    return 0;
}
