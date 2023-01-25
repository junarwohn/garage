#include <stdio.h>
int main(void) {
    int ang_1, ang_2, ang_3;
    scanf("%d %d %d", &ang_1, &ang_2, &ang_3);
    if (ang_1 == 60 && ang_2 == 60 && ang_3 == 60) {
        printf("Equilateral\n");
    } else {
        int sum = ang_1 + ang_2 + ang_3;
        if (sum == 180) {
            if (ang_1 == ang_2 || ang_1 == ang_3 || ang_2 == ang_3)
                printf("Isosceles\n");
            else 
                printf("Scalene\n");
        } else {
            printf("Error\n");
        }
    }
    return 0;
}
