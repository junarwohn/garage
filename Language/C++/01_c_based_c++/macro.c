#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define RGB(r, g, b) ((b) * 256 * 256 + (g) * 256 + (r))
int main(void)
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
 
    printf("#%06X\n", RGB(r, g, b));
    printf("#%06X\n", RGB(1 & 1, 2 & 2, 3 & 3));
    return 0;
}
