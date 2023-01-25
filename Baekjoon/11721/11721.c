#include <stdio.h>
int main(void) {
		char input[101];
		scanf("%s", input);
		char * det = input;
		while(* det != '\0') {
			for (int i = 0; i < 10; i++) {
					
					printf("%c", * det);
					det++;
			}
			printf("%c", '\n');
		}
		return 0;
}
