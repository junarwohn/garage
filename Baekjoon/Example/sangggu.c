#include <stdio.h>
int factorial(int x)
{   
    int result= 1;

    for(; x >0; x--)
    {
        result = result * x;
    }
    
    return result;
}

int main(void) {
    char cmd[3];
    scanf("%2s",cmd);
    while (getchar() != '\n');
    
    return 0;
}