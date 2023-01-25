#include <stdio.h>
#include <stdlib.h>
int findTime(int * matrix, int start, int end, int result) {
		int D_ = sizeof(matrix[0])/sizeof(int);
		int max_result = 0;
		if (matrix[start][end]) {
				int tmp = 0;
				for (int i = 0 ; i < D_; i++) {
						if (matrix[end][i]) {
								tmp = findTime(matrix, end, i);
								
						}
				}
}
int main(void) {
		int T = 0;
		scanf("%d", &T);
		for (int i = 0; i < T; i++) {
				int N, K;
				scanf("%d %d", &N, &K);
				int D = 0;
				scanf("%d", &D);
				int ** Matrix = (int **) malloc(sizeof(int *) * D);
				for (int j = 0; j < D; j++) {
						Matrix[j] = (int *) malloc(sizeof(int) * D);
						for (int k = 0; k < D; k++) {
								Matrix[j][k] = 0;
						}
				}
				int coordinate[2];
				for (int j = 0; j < D; j++) {
						scanf("%d %d", coordinate, coordinate + 1);
						Matrix[coordinate[0]][coordinate[1]] = 1;
				}

				
