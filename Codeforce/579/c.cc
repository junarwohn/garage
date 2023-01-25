#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	long long * s = new long long[n];
	long long input;
	long long gcd_result;
	cin >> gcd_result;
	for (long long i = 1; i < n; i++) {
		cin >> input;
		gcd_result = gcd(gcd_result, input);
	}
	long long result = 0;
	for (long long i = 1; i*i <= gcd_result; i++) {
		if (gcd_result % i == 0) {
			if (i * i != gcd_result)
				result++;
			result++;
		}
	}
	cout << result << '\n';
	return 0;
}
