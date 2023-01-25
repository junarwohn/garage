#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int N = 0;
    scanf("%d", &N);
    int * list = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", list + i);
    for (int bubble_end = N; bubble_end > 0; bubble_end--) {
        for (int cmp = 0; cmp < bubble_end - 1; cmp++) {
            if (list[cmp] > list[cmp + 1]) {
                int tmp = list[cmp];
                list[cmp] = list[cmp + 1];
                list[cmp + 1] = tmp;
            }
        } 
    }
    for (int i = 0; i < N; i++)
        printf("%d\n", list[i]);
    return 0;
}