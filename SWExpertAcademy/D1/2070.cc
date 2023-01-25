#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, det;
		cin >> a >> b;
		det = (a - b);
		cout << '#' << i + 1 << ' ' <<  (char) ('=' + ((det > 0) - (det < 0))) << '\n';
	}
	return 0;
}
