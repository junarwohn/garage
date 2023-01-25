#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ARR[6] = {4, 8, 15, 16, 23, 42};
	int get_index[43] = {0,};
	for (int i = 0; i < 6; i++) {
		get_index[ARR[i]] = i;
	}
	int cnt[6] = {0, };
	int * a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n < 6) {
		cout << n << '\n';
	} else {
		for (int t = 0; t < n; t++) {
			if (a[t] != 4 && cnt[get_index[a[t]] - 1] == cnt[get_index[a[t]]])
				continue;
			cnt[get_index[a[t]]]++;
			a[t] = 0;
		}	
		int match = cnt[0];	
		for (int i = 1; i < 6; i++) {
			match = match <= cnt[i] ? match : cnt[i];
		}
		for (int i = 0; i < 6; i++)
			cnt[i] -= match;
		int remove = 0;
		for (int i = 0; i < 6; i++)
			remove += cnt[i];
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) {
				remove++;
			}
		}
		cout << remove << '\n';
	}
	return 0;
}
