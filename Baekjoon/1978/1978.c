#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N = 0;
    scanf("%d", &N);
    int * input_list = (int *)malloc(sizeof(int) * N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", input_list + i);
        if (max < input_list[i])
            max = input_list[i];
    }
    int * prime_num_list = (int *)malloc(sizeof(int) * (max + 2));
    for (int i = 1; i <= max; i++) {
        prime_num_list[i] = 0;
    }
    prime_num_list[1] = 1;
    for (int i = 2; i <= max; i++) {
        if (prime_num_list[i])
            continue;
        for (int j = 2; (j * i <= max); j++) {
            prime_num_list[i * j]++;           
        }
    }

    int num_of_prime = 0;
    for (int i = 0; i < N; i++) {
        if (!prime_num_list[input_list[i]])
            num_of_prime++;
    }
    printf("%d", num_of_prime);
    free(prime_num_list);
    free(input_list);
    return 0;
}