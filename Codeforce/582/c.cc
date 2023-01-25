#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int pattern[10] = {0, };
	int q;
	cin >> q;
	for (int t = 0; t < q; t++) {
		long long int n, m;
		cin >> n >> m;
		long long int divided = n / m;
		int first_digit = m % 10;
		for (int i = 0; i < 10; i++)
			pattern[i] = (first_digit * i) % 10;
		long long int sum = 0;
		int pattern_sum = 0;
		for (int i = 0; i < 10; i++)
			pattern_sum += pattern[i];
		sum += (divided / 10) * pattern_sum;
		for (int i = 0; i <= divided % 10; i++)
			sum += pattern[i];
		cout << sum << '\n';
	}
	return 0;
}

