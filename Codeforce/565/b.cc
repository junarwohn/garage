#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n;
		cin >> n;
		int * a = new int[n];
		int cnt[3] = {0, };
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a[i] = tmp % 3;
			cnt[a[i]]++;
		}
		int merge_cnt = cnt[1] > cnt[2] ? cnt[2] : cnt[1];
		int rest = cnt[1] - cnt[2];
		if (rest < 0)
			rest *= -1;
		cout << cnt[0] + merge_cnt + rest / 3 << '\n';
	}
	return 0;
}
