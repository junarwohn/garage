#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N = 0;
	int in = 0;
	scanf("%d", &N);
	int * list = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &(list + i));
		int j = 0;
		for (j = 0; j < i; j++) {
			if (in > list[j])
				break;
		}
		int 
		for (; j < i; j++) {
			
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", list[i]);
	return 0;
}
