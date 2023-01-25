#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int k,n;
        scanf("%d %d", &k, &n);
        int * list = (int *)malloc(sizeof(int) * n);
        for (int index = 0; index < n; index++) {
            list[index] = 1;
        }
        for (int floor = 0; floor <= k; floor++) {
            for (int room = 1; room < n; room++) {
                list[room] += list[room - 1];
            }
        }
        printf("%d\n", list[n-1]);
    }
    return 0;
}