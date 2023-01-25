#include <stdio.h>
int main(void){
    double a;
    double b;
    double result;
    scanf("%lf %lf", &a, &b);
    result = a/b;
    printf("%-10.10f", result);
    return 0;
}