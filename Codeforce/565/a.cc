#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;	
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long int n;
		cin >> n;
		int cnt[3] = {0, };
		for (int t = 2, k = 1; t <= 5; k++) {
			while (n % t == 0) {
				cnt[k - 1]++;
				n /= t;
			}
			t += k;
		}
		if (n == 1)
			cout << (cnt[0] + 2 * cnt[1] + 3 * cnt[2]) << '\n';
		else
			cout << "-1\n";
		
	}
	return 0;
}
