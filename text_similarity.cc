#include <iostream>

int max_len = 10000000;
using namespace std;

struct vertex {
       int v, r, c;
};       

int cmp_similarity(char *A, char *B, int len_A, int len_B) {
	struct vertex map[len_A][len_B];
	for (int idx_a = 0; idx_a < len_A; ++idx_a) {
		for (int idx_b = 0; idx_b < len_B; ++idx_B) {
			map[idx_a][idx_b] = {-2, 0, 0};
			if (A[idx_a - 1] == B[idx_b - 1]) {
				map[idx_a][idx_b].v = 3;
			}
		}
	}
	return 0;
}


int main(void) {
	int len_A, len_B;
	char A[max_len], B[max_len];
	cin >> len_A >> A >> len_B >> B;
	cout << A << B << '\n';
	return 0;
}

