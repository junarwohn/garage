#include <stdio.h>
int main(void) {
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b, det;
		scanf("%d %d", &a, &b);
		det = a - b;
		printf("#%d %c\n", i + 1, '=' + ((det > 0) - (det < 0)));
	}
	return 0;
}
