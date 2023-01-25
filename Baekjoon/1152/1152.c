#include <stdio.h>
int main(void) {
		char input[1000001];
		gets(input);
		int i = 0;
		int in = 0;
		int cnt = 0;
		while (input[i] != '\0') {
				if (input[i] != ' ') {
						in = 1;
				} else if (input[i] == ' ') {
						if (in) {
								cnt++;
						}
						in = 0;
				}
				i++;
		}
		if (in) {
				cnt++;
		}
		printf("%d" , cnt);
		return 0;
}
