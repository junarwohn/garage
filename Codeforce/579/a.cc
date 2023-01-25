#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		int cnt_plus = 0;
		int cnt_minus = 0;
		int * input_list = new int[n];
		for (int s = 0; s < n; s++) {
			cin >> input_list[s];
		}

		if (n == 1) {
			cout << "YES\n";
			continue;
		}

		for (int s = 0; s < n; s++) {
			int delta = input_list[s] - input_list[(s + 1) % n];
			if (delta == -1) {
				cnt_minus++;
			} else if (delta == 1) {
				cnt_plus++;
			} else {
				continue;
			}
		}
		if (cnt_plus == n - 1 || cnt_minus == n - 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
