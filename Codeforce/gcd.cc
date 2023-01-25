#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// using A = Bq + r
	/*
	int a, b; cin >> a >> b;
	int r1 = b, r2 = a % b, tmp;
	while(r2 != 0) {
		tmp = r2;
		r1 = r2;
		r2 = tmp % r2;
	};
	*/

	int a, b; cin >> a >> b;
	if (b > a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	cout << gcd(a, b) << '\n';
	return 0;
}

	
