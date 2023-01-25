#include <stdio.h>
int main(void) {
    int i = 0;
    int n[3] = {1, 1, 1};
    while (0 < n[i++])
        printf("%d", n[i]);
    // while (i++ < 0)
        // printf("%d", i);
    // printf("%d", i);
    return 0;
}