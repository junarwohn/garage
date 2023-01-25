#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long int a, b, k;
		cin >> a >> b >> k;
		long long int even_times = k / 2;
		int additional_move = k % 2;
		long long int result = (long long int) ((a - b) * even_times);
		result += (long long int) (a * additional_move);
		cout << result << '\n';
	}
	return 0;
}
