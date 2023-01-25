#include <stdio.h>
int main(){
    char dial[16];
    int result = 0;
    scanf("%s", dial);
    for (int i = 0; dial[i] != '\0'; i++) {
        int time = 2;
        if (dial[i] <= 'C') {
            time += 1;
        } else if (dial[i] <= 'F') {
            time += 2;
        } else if (dial[i] <= 'I') {
            time += 3;
        } else if (dial[i] <= 'L') {
            time += 4;
        } else if (dial[i] <= 'O') {
            time += 5;
        } else if (dial[i] <= 'S') {
            time += 6;
        } else if (dial[i] <= 'V') {
            time += 7;
        } else if (dial[i] <= 'Z') {
            time += 8;
        }
        result += time;
    }
    printf("%d", result);
    return 0;
}