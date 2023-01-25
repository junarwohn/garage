#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long double len(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int start[2];
		int destination[2];
		scanf("%d %d %d %d", start, start + 1, destination, destination + 1);
		int N = 0;
		scanf("%d", &N);

		int ** orbit = (int **)malloc(sizeof(int *) * N);
		for (int j = 0; j < N; j++) 
			orbit[j] = (int *)malloc(sizeof(int) * 3);
		for (int j = 0; j < N; j++) {
			scanf("%d %d %d", &orbit[j][0], &orbit[j][1], &orbit[j][2]);
		}
		int * A = malloc(sizeof(int) * N);
		int * B = malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			A[j] = 0;
			B[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			if (len(start[0], start[1], orbit[j][0], orbit[j][1]) < orbit[j][2]) {
				A[j] = 1;
		//		printf("n-th is %d s[0] %d s[1] %d o[0] %d o[1] %d o[2] %d\n", j, start[0], start[1], orbit[j][0], orbit[j][1], orbit[j][2]);
			}
			if (len(destination[0], destination[1], orbit[j][0], orbit[j][1]) < orbit[j][2]) {
				B[j] = 1;
		//		printf("n-th is %d d[0] %d d[1] %d o[0] %d o[1] %d o[2] %d\n", j, start[0], start[1], orbit[j][0], orbit[j][1], orbit[j][2]);
			}
		}
		int result = 0;
		//for (int j = 0; j < N; j++) {
		//	printf("A[%d] : %d , B[%d] : %d\n", j, A[j], j, B[j]);
		//}
		for (int j = 0; j < N; j++) {
			if (A[j] == 1)
				result++;
			if (B[j] == 1)
				result++;
			if (A[j] == 1 && B[j] == 1)
				result-=2;
		//	printf("%d result is %d\n", j, result);
		}
		printf("%d\n", result);
		free(A);
		free(B);
		free(orbit[0]);
		free(orbit);
	}
	return 0;
}
