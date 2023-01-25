#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int sum = 0, min = 0, max = 0, input;
		cin >> input;
		min = max = input;
		sum += input;
		for (int t = 1; t < 10; t++) {
			cin >> input;
			sum += input;
			if (min > input)
				min = input;
			if (max < input)
				max = input;
		}
		cout << '#' << i + 1 << ' ' << (int) (((float)(sum - max - min) / 8) + 0.5) << '\n';

	}

	return 0;
}
