#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int tmp, max = 0;
		for (int t = 0; t < 10; t++) {
			cin >> tmp;
			if (max < tmp)
				max = tmp;
		}
		printf("#%d %d\n", i + 1, max);
	}
	return 0;
}
