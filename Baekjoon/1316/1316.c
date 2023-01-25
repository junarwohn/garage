#include <stdio.h>
int main(void) {
    char input[101];
    int N = 0;
    scanf("%d", &N);
    int result = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", input);
        char status = 1;
        char pre = input[0];
        char alpha_list['z' - 'a' + 1] = {0};
        alpha_list[pre - 'a']++;
        for (int input_index = 1; input[input_index] != '\0'; input_index++) {
            if (alpha_list[input[input_index] - 'a'] != 0) {
                if (pre != input[input_index]) {
                    status = 0;
                    break;
                }
            }
            alpha_list[input[input_index] - 'a']++;
            pre = input[input_index];
        }
        result += status;
    }
    printf("%d", result);
    return 0;
}