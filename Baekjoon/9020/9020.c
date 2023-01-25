#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int g = 0;
        scanf("%d", &g);
        int * prime_num_list = (int *)malloc(sizeof(int) * (g + 1));
        int x = 0, y= g;
        prime_num_list[1] = 1;
        for (int i = 2; i <= g; i++)
            prime_num_list[i] = 0;
        for (int i = 1; i <= g; i++) {
            if (prime_num_list[i])
                continue;
            for (int j = 2; (j * i) <= g; j++)
                prime_num_list[i * j]++;
        }
        for (int i_x = 2; i_x <= (g + 1) / 2; i_x++){
            int i_y = g - i_x;
            if (!prime_num_list[i_x] && !prime_num_list[i_y]) {
                if (i_y - i_x < y - x) {
                    x = i_x;
                    y = i_y;
                }
            }
        }
        printf("%d %d\n", x, y); 
        free(prime_num_list);
    }
    return 0;
}
