#include <stdio.h>
int main(void) {
    long long int n = 0;
    scanf("%lld", &n);
    int num_list[10] = {0,};
    do {
        num_list[n%10]++;
    }
    while (n /= 10);
    num_list[6] += ++num_list[9];
    num_list[6] /= 2;
    int max = num_list[0];
    for (int i = 1; i < 9; i++)
        if (max < num_list[i])
            max = num_list[i];
    printf("%d", max);
    return 0;
}