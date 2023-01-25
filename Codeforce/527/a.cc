#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k;
	cin >> t;
	for(int trial = 0; trial < t; trial++) {
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cout << char('a' + i % k);
		}
		cout << '\n';
	}
	return 0;
}

