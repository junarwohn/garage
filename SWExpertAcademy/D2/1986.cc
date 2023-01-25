#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int t = 0; t < q; t++) {
		int n;
		cin >> n;
		if (n % 2 == 0)
			cout << '#' << t + 1 << ' ' << -1 * n / 2 << '\n';
		else 
			cout << '#' << t + 1 << ' ' <<  (n + 1) / 2 << '\n';
	}
	return 0; 
}

			
