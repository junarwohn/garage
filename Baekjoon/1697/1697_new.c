#include <stdio.h>
#include <stdlib.h>
int pow3(int n) {
		int result = 1;
		for (int i = 0; i < n; i++) {
				result *= 3;
		}
		return result;
}
struct path {
		int * search_list;
};
int main(void) {
		int N, K;
		scanf("%d %d", &N, &K);
		if (N >= K) {
				printf("%d", N -K);
		} else {
				int result = 0;
				struct path FIND[2];
				FIND[0].search_list = malloc(sizeof(int));
				FIND[0].search_list[0] = N;
				FIND[1].search_list = malloc(sizeof(int));
				char is_reached = 0;
				while (!is_reached) {
						result++;
						FIND[result%2].search_list = malloc(sizeof(int) * pow3(result));
						for (int i = 0; i < pow3(result - 1); i++) {
								int insert = FIND[(result + 1)%2].search_list[i];
								FIND[result%2].search_list[3 * i] = insert - 1;
								FIND[result%2].search_list[3 * i + 1] = insert + 1;
								FIND[result%2].search_list[3 * i + 2] = 2 * insert;
						}
						for (int i = 0; i < pow3(result); i++) {
								if(FIND[result%2].search_list[i] == K) {
										is_reached = 1;
								}
						}
						free(FIND[(result + 1) % 2].search_list);
				}
				printf("%d", result);
		}
		return 0;
}
