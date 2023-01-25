#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		int * input_list = new int[4 * n];
		for (int s = 0; s < 4 * n; s++) {
			cin >> input_list[s];
		}
		sort(input_list, input_list + 4 * n);
		int iter_l = 0;
		int iter_r = 4 * n - 1;
		int * ret_vol = new int[n];
		bool is_possible = true;
		for (int ret_index = 0; ret_index < n; ret_index++) {
			if (input_list[iter_l] == input_list[iter_l + 1] && input_list[iter_r] == input_list[iter_r - 1]) {
				ret_vol[ret_index] = input_list[iter_l] * input_list[iter_r];
				iter_l += 2;
				iter_r -= 2;
			} else {
				is_possible = false;
				break;
			}
		}
		for (int ret_index = 0; ret_index < n - 1; ret_index++) {
			if (ret_vol[ret_index] != ret_vol[ret_index + 1]) {
				is_possible = false;
				break;
			}
		}
		if (is_possible) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
