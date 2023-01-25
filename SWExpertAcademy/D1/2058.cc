#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, sum = 0;
	cin >> N;
	while (N != 0) {
		sum += N % 10; N /= 10;
	}
	cout << sum << '\n';
	return 0;
}
