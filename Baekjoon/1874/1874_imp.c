#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int n = 0;
    scanf("%d", &n);
    
    char * push_and_pop_list = (char *)malloc(sizeof(char) * 2 * n);
    int push_cnt = 0;
    int pop_cnt = 0;
    
    int * Stack = (int *)malloc(sizeof(int) * (n + 1));
    *Stack = -1;
    int * Top = Stack;
    int input_num = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input_num);
        while (input_num > *Top) {
            *(Top + 1) = push_cnt + 1;
            push_and_pop_list[pop_cnt + push_cnt++] = '+'; 
            Top++;
        }
        if (input_num == *Top) {
            Top--;
            push_and_pop_list[push_cnt + pop_cnt++] = '-';
        } else {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = 0; i < 2 * n; i++)
        printf("%c\n", push_and_pop_list[i]);
    return 0;
}
