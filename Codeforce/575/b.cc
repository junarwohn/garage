#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, k;
		cin >> n >> k;
		int * arr = new int[n];
		int input_num = 0;
		int total_odd = 0;
		for (int t = 0; t < n; t++) {
			cin >> input_num;
			arr[t] = input_num % 2;
			if (arr[t] == 1)
				total_odd++;
		}
		if (total_odd < k || (total_odd - k) % 2 != 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			int k_cnt = k - 1;
			for (int arr_iter = 0; k_cnt != 0; arr_iter++) {
				if (arr[arr_iter] == 1) {
					cout << arr_iter + 1 << ' ';
					k_cnt--;
				}
			}
			cout << n << '\n';
		}
	}
	return 0;
}
