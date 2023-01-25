#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			cout << i << ' ';
	cout << i;
	return 0;
}
