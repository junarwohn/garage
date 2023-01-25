#include <iostream>
using namespace std;

int abs(unsigned int x) {
	return x > 0 ? x : -1 * x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	unsigned int * x = new unsigned int[q];
	for (int i = 0; i < q; i++) {
		cin >> x[i];
		x[i] %= 2;
	}
	int odd_sum = 0, even_sum = 0;
	for (int i = 0; i < q; i++) {
		if (x[i] == 0)
			even_sum++;
		else 
			odd_sum++;
	}
	int min_sum = even_sum > odd_sum ? odd_sum : even_sum;
	cout << min_sum  << '\n';
	return 0;

}



		
