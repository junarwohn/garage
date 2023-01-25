#include <stdio.h>
char det(char a) {
		if ((a == 0) || ((a >= 48) && (a <= 57)) || ((a >= 65) && (a <= 90)) || (a == 32) || ((a >= 97) && (a <= 122))) {
				return 1;
		} else {
				return 0;
		}
}
int main(void) {
		int index = 0;
		char input[101];
		char is_ok = 1;
		while (gets(input)) {
				for (int i = 0; input[i] != '\0'; i++) {
						if (det(input[i]) == 0) {
							is_ok = 0;		
							break;	
						}
				}
				if (is_ok == 0) {
						break;
				}
				puts(input);
		}
		return 0;
}

