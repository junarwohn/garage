#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, n, index;
	cin >> q;
	for (int t = 0; t < q; ++t) {
		cin >> n;
		int * cnt = new int[n];
		for (int i = 0; i < n; ++i)
			cnt[i] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> index;
			cnt[index - 1]++;
		}
		sort(cnt, cnt + n, greater<int>());
		int max_sum = cnt[0];
		int max_candy = cnt[0];
		int delta = 0;
		for (int i = 1; i < n && max_candy > 0; ++i) {
			if (max_candy <= cnt[i]) {
				--max_candy;
			} else {
				max_candy = cnt[i];
			}
			max_sum += max_candy;
		}
		cout << max_sum << '\n';
		delete[] cnt;
	}
	return 0;
}
