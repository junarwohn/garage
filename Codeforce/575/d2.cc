#include <iostream>
#include <algorithm>
using namespace std;
char REF[4] = "RGB";
char s[200001];
int delta[3][200001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, n, k;
	cin >> q;
	for (int t = 0; t < q; t++) {
		cin >> n >> k;
		cin >> s;
		int cnt = 200001;
		for (int r = 0; r < 3; ++r) {
			for (int i = 0; i < n; ++i) {
				delta[r][i] = s[i] - REF[(i + r) % 3] == 0 ? 0 : 1;
			}
		}
		for (int r = 0; r < 3; ++r) {
			int sum = 0;
			for (int i = 0; i < k; ++i) sum += delta[r][i];
			cnt = min(cnt, sum);
			for (int i = k; i < n; ++i) {
				sum -= delta[r][i - k];
				sum += delta[r][i];
				cnt = min(cnt, sum);
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}


