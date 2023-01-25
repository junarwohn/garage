#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N = 0;
    scanf("%d", &N);
    int * list = (int *)malloc(sizeof(int) * N + 1);
    for (int i = 1; i <= N; i++)
        list[i] = 0;
    scanf("%d", list + 1);
    for (int i = 2; i <= N; i++) {
        scanf("%d", list + i);
        int index = i;
        while (index != 1) {
            if (list[index] < list[index/2]) {
                int tmp = list[index];
                list[index] = list[index/2];
                list[index/2] = tmp;
                index /= 2;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d\n", list[1]);
        list[1] = list[N - i + 1];
        list[N - i + 1] = 1000001;
        for (int index = 1; index * 2 <= N - i;){
            int min_index = list[index * 2] < list[index * 2 + 1] ? index * 2 : index * 2 + 1;
            if (list[index] > list[min_index]) {
                int tmp = list[index];
                list[index] = list[min_index];
                list[min_index] = tmp;
                index = min_index;
            } else {
                break;
            }
        }
    }
    return 0;
}
