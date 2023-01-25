#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("#%d\n", i + 1); 
		for (int h = 0; h < n; h++) {
			int n_pac = 1;
			int r_pac = 1;
			int n_r_pac = 1;
			for (int p = 1; p <= h; p++)
				n_pac *= p;	
			n_r_pac = n_pac;
			for (int w = 0; w < h + 1; w++) {
				r_pac *= (w != 0 ? w : 1);
				printf("%d ", (n_pac / r_pac) / n_r_pac);
				n_r_pac /= (h - w != 0 ? (h - w) : 1);
		}
			printf("\n");
		}
	}
	return 0;
}

