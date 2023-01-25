#include <stdio.h>
#include <stdlib.h>

int main(void) {
		int min, min_i, max, max_i;
		int N = 0;
		int input = 0;
		scanf("%d", &N);
		int * list = (int *)malloc(sizeof(int) * N);
		scanf("%d", list);
		min = list[0];
		max = list[0];
		for (int i = 1; i < N; i++) {
				scanf("%d", &input);
				list[i] = list[i - 1] + input;
				if (max < list[i]) {
						max_i = i;
						max = list[i];
				}
				if (min > list[i]) {
						min_i = i;
						min = list[i];
				}
		}
		printf("%d", max - min);
		return 0;
}
