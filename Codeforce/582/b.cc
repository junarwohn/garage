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
		int * prices = new int[n];
		int * min_after = new int[n];
		for (int i = 0; i < n; i++)
			cin >> prices[i];
		int min = prices[n - 1];
		for (int i = n - 1; i >= 0; --i) {
			if (prices[i] < min)
				min = prices[i];
			min_after[i] = min;
		}
		int cnt_bad = 0;
		for (int i = 0; i < n; i++)
			if (prices[i] > min_after[i])
				cnt_bad++;
		cout << cnt_bad << '\n';
		delete[] prices;
		delete[] min_after;
	}
	return 0;
}
