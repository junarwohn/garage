#include <stdio.h>
int main(void) {
		int index = 0;
		char input[101];
		while (gets(input)) {
				if (input[0] == '\0' || input[0] == ' ') {
						break;
				}
				puts(input);
		}
		return 0;
}
