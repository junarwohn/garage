#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int run_prime_filter(bool *&_filter , int _n) {
	if (_n < 100000) 
		_n *= 10;
	else
		_n = 10000004;
	_filter = new bool[_n + 1];
	memset(_filter, true, (_n + 1) * sizeof(bool));
	_filter[1] = false;
	for (int i = 2; i <= (int)sqrt(_n); i++) {
		if (_filter[i]) 
			for (int de = i * i; de <= _n; de += i) 
				_filter[de] = false;	
		else 
			continue;
	}
	return _n;
}	

int main(void) {
	int N;
	bool * filter;
	cin >> N;
	int range = run_prime_filter(filter, N);
	string origin_num, cmp_num;
	for (int i = N; i <= range; i++) {
		if (filter[i]) {
			origin_num = to_string(i);
			cmp_num = origin_num;
			reverse(cmp_num.begin(), cmp_num.end());
			if (origin_num.compare(cmp_num) == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	delete[] filter;
	return 0;
}
