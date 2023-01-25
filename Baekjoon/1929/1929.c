#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N_1 = 0, N_2 = 0;
    scanf("%d", &N_1);
    scanf("%d", &N_2);
    int * prime_num_list = (int *)malloc(sizeof(int) * (N_2 + 1));
    for (int i = 1; i <= N_2; i++) {
        prime_num_list[i] = 0;
    }
    prime_num_list[1] = 1;
    for (int i = 2; i <= N_2; i++) {
        if (prime_num_list[i])
            continue;
        for (int j = 2; (j * i <= N_2); j++) {
            prime_num_list[i * j]++;           
        }
    }

    for (int i = N_1; i <= N_2; i++) {
        if (!prime_num_list[i])
            printf("%d\n", i);
    }
    free(prime_num_list);
    return 0;
}