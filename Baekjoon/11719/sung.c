#include <stdio.h>
#include <stdlib.h>

int ch;

int main(void){
	while((ch = getchar())!='\0')
        printf("%c",ch);
    return 0;
}