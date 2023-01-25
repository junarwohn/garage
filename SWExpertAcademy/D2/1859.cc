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
		int * chart = new int[n];
		for (int i = 0; i < n; i++)
			cin >> chart[i];
		int * max_price_chart = new int[n];
		int max_price = chart[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			if (max_price < chart[i])
				max_price = chart[i];
			max_price_chart[i] = max_price;
		}
		long long int profit = 0;
		for (int i = 0; i < n; i++)
			profit += max_price_chart[i] - chart[i];
		printf("#%d %lld\n", t + 1, profit);
		delete max_price_chart;
	}
	return 0;
}
