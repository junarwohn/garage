#include <stdio.h>

int main(void) {
    double k = 1 / 0.0000000000000000000000000000000000000000000000000000001;
    printf("%lf", k);
    return 0;

}
