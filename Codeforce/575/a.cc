#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long int sum_of_piles = 0;
		long long int pile;
		for (int t = 0; t < 3; t++) {
			cin >> pile;
			sum_of_piles += pile;
		}
		cout << (sum_of_piles / 2) << '\n';
	}
	return 0;
}
