#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int sum = 0;
		int tmp;
		for (int t = 0; t < 10; t++){
			cin >> tmp;
			sum += tmp;
		}
		if (sum % 10 >= 5)
			sum += 10;
		sum /= 10;
		cout << '#' << i + 1 << ' ' << sum << '\n';
	}
	return 0;
}
