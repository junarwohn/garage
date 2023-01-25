#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	int clap_rule[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 1};
	int clap[1001] = {0 ,};
	if (n > 100) {
		for (int a = 0; a < 10; a++)
			for (int b = 0; b < 10; b++)
				for (int c = 0; c < 10; c++)
					clap[100 * a + 10 * b + c] += clap_rule[a] + clap_rule[b] + clap_rule[c];
	} else {
		for (int a = 0; a < 10; a++)
			for (int b = 0; b < 10; b++)
				clap[10 * a + b] += clap_rule[a] + clap_rule[b];
	}
	for (int i = 1; i <= n; i++) {
		if (clap[i] == 0) {
				cout <<  i << ' ';
		} else {
			for (int k = 0; k < clap[i]; k++) {
				cout << '-';
			}
			cout << ' ';
		}
	}
	return 0;
}


	
