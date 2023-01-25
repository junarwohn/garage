#include <stdio.h>
int main(void) {
		int N = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
				int j = 0;
				for (j = 0; j < i; j++) {
					printf(" ");
				}
				for (; j < N; j++) {
						printf("*");
				}
				if (i != N - 1) 
					printf("\n");
		}
		return 0;
}
