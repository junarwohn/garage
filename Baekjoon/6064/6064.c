#include <stdio.h>
int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int k = 0, l = 0;  
        for (k = 0; k <= N; k++) {
            if ((M * k + x - y) % N == 0) {
                l = (M * k + x - y)/N;
                break;
            }
        }
        if ((M * k + x) == (N * l + y)) {
            printf("%d\n", M * k + x);
        } else {
            printf("-1\n");
        }
    }
}