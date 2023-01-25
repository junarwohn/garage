#include <iostream>

using namespace std;

int max_delete(int * list, int len) {
	int max_index = 0;
	int max_val = list[0];
	for (int i = 0; i < len; i++) {
		if (list[i] > max_val) {
			max_val = list[i];
			max_index = i;
		}
	}
	if (max_val <= 0)
		return -1;
	else
		return max_index;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int * a = new int[n];
	int * check_list = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check_list[i] = 0;
	}
	for (int i = 0; i < n - 2; i++) {
		if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1) {
			check_list[i]++;
			check_list[i + 2]++;
		}
	}
	int change_cnt = 0;
	int ret;
	while (true) {
		ret = max_delete(check_list, n);
		if (ret == -1) {
			break;
		} else {
			check_list[ret] = -1;
			check_list[ret + 2] = -1;
			if (ret >= 2) 
				check_list[ret - 2] = -1;	
			change_cnt++;
		}
	}
	cout << change_cnt << '\n';
	return 0;
}
