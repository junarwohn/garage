#include <stdio.h>
int main(void) {
    char input[2][4];
    scanf("%s %s", input[0], input[1]);
    int index = 0;
    if (input[0][2] != input[1][2]) {
        if (input[0][2] < input[1][2]) {
            index = 1;
        }
    } else if (input[0][1] != input[1][1]) {
        if (input[0][1] < input[1][1]) {
            index = 1;
        }
    } else {
        if (input[0][2] < input[1][2]) {
            index = 1;
        }
    }
    printf("%c%c%c", input[index][2], input[index][1], input[index][0]);
    return 0;
}