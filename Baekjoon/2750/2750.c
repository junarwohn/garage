#include <stdio.h>
#include <stdlib.h>

// pivot to middle
void quick(int * list_, int s, int e) {
    int i = s, j = e;
    int tmp;
    int p_val = list_[(s + e) / 2];
    do {
        while (p_val > list_[i])
            i++;
        while (p_val < list_[j])
            j--;
        if (i <= j) {
            // swap i j
            tmp = list_[i];
            list_[i++] = list_[j];
            list_[j--] = tmp;
        }
    } while (i <= j);
    if (s < j)
        quick(list_, s, j);
    if (i < e)
        quick(list_, i, e);
}

int main(void) {
    int N = 0;
    scanf("%d", &N);
    int * list = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", list + i);
    }
    quick(list, 0, N - 1);
    for (int i = 0; i < N; i++) 
        printf("%d\n", list[i]);
}