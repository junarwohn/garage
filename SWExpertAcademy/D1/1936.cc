#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int det = a - b;
	if (det == 1 || det == -2)
		cout << 'A';
	else
		cout << 'B';
	return 0;
}
