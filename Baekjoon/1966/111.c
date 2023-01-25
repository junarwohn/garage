#include <stdio.h>
int main(void) {
    int n = 100;
    switch(n/10) {
        case 1:
        case 2:
            printf("d");
            break;
        case 9:
            printf("A");
            break;
    }
    return 0;
}