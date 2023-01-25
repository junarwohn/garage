#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = n; i > -1; i--)
		cout << i << ' ';
	return 0;
}
