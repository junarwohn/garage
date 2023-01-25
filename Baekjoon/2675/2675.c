#include <stdio.h>

int main(void) {
    int T = 0;
    char input_str[21];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N = 0;
        scanf("%d", &N);
        scanf("%s", input_str);
        for (int j = 0; input_str[j] != '\0'; j++) {
            for (int k = 0; k < N; k++) {
                printf("%c", input_str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}