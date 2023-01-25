#include <stdio.h>
int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int H,W,N;
        scanf("%d %d %d", &H, &W, &N);
        int r_n = 0, f_r= 0;
        for (; H * (r_n + 1) < N; r_n++);
        f_r = N - r_n * H;
        printf("%d%02d\n", f_r, r_n + 1);
    }
    return 0;
}