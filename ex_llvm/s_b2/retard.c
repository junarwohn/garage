#include <stdio.h>

int add_inst_count = 0;

int main(void) {
    int sum = 0;

    sum = sum + 1;
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }
    printf("Total Sum : %d\n", add_inst_count);
    return 0;
}
