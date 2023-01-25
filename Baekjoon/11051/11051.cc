#include <iostream>
using namespace std;
int ** saved_arr;
int pascal_method(int n_, int r_) {
	if (saved_arr[n_][r_]) {
		return saved_arr[n_][r_];
	} else {
		return saved_arr[n_][r_] = ((pascal_method(n_- 1, r_ - 1) % 10007) + (pascal_method(n_- 1, r_) % 10007)) % 10007;
	}
}
int main(void) {
	int N, K;
	cin >> N >> K;
	saved_arr = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		saved_arr[i] = new int[N + 1]();
	}
	for (int i = 0; i <= N; i++) {
		saved_arr[i][i] = 1;
		saved_arr[i][0] = 1;
		saved_arr[i][1] = i;
	}
	cout << pascal_method(N, K) << endl;
	delete saved_arr;
	return 0;
}
