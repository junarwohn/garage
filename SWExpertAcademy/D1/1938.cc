#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << a + b << '\n' << a - b << '\n' << a * b << '\n' << a / b;
	return 0;
}
