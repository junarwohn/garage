#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N = 0;
    scanf("%d", &N);
    int * list = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int in;
        scanf("%d", &in);
        int swap_index = 0;
        for (;swap_index < i; swap_index++) {
            if (list[swap_index] > in) {
                break;
            }
        }
        for (int push_index = i; push_index > swap_index; push_index--)
            list[push_index] = list[push_index - 1];
        list[swap_index] = in;
    }
    for (int i = 0; i < N; i++)
        printf("%d\n", list[i]);
}