#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    char Stack[32];
	char input[32];
    int Top = 0;
    int result = 0;
    int weight = 1;
    int is_pushed = 1;
	scanf("%s", input);
	for (int k = 0; input[k] != '\0'; k++) {
        Stack[++Top] = input[k];
        if (Stack[Top] == '[' || Stack[Top] == '(') {
          
            weight *= (Stack[Top] == '[' ? 3 : 2);
            is_pushed = 1;
            continue;
        } else if (Stack[Top] == ']' || Stack[Top] == ')') {
            
            if (Top <= 1) {
                printf("0\n");
                return 0;
            }

            char cmp_char = (Stack[Top] == ']' ? '[' : '(');
            if (Stack[Top - 1] != cmp_char) {
                printf("0\n");
                return 0;
            }   
            int val = (cmp_char == '[' ? 3 : 2);
            if (is_pushed) {
                is_pushed = 0;
                result += weight;
            }
            weight /= val;
            Top -= 2;

        } else {
        
            printf("sival");
            return 0;
        
        }
    }
    if (Top != 0) 
        printf("0\n");
    else                 
        printf("%d\n", result);         
    return 0;
}
