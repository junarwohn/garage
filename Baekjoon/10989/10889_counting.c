#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int N = 0;
    scanf("%d", &N);
    int count_list[10001] = {0,};
    int input = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &input); 
        count_list[input]++;
    }
    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < count_list[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}
