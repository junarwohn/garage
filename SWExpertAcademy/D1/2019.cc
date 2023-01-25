#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k = 1;
	cin >> n;
	for (int i = 0; i < n; i++, k *= 2)
		cout << k << ' ';
	return 0;
}
