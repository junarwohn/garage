#include <iostream>
#include <algorithm>

#define _MAX_DIVIDE	20
#define _MAX_NUM 200001

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int * a = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	long long ** divide_list = new long long *[_MAX_DIVIDE];
	for (int i = 0; i < _MAX_DIVIDE; i++) {
		divide_list[i] = new long long[_MAX_NUM];
		for (int j = 0; j < _MAX_NUM; j++) {
			divide_list[i][j] = 0;
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		divide_list[0][a[i]]++;
		if (a[i] > max)
			max = a[i];
	}
	int search_max = max;
	for (int trial = 1; trial < _MAX_DIVIDE; trial++) {
		for (int num = 1; num <= search_max; num++) {
			divide_list[trial][num / 2] += divide_list[trial - 1][num];
		}
		search_max /= 2;
	}
	long long result = -1;
	for (int search_num = max; search_num >= 0; search_num--) {
		long long num_cnt = 0;
		long long change_cnt = 0;
		for (int trial = 0; trial < _MAX_DIVIDE; trial++) {
			num_cnt += divide_list[trial][search_num];
			change_cnt += trial * divide_list[trial][search_num];
			if (num_cnt == k) {
				if (result == -1)
					result = change_cnt;
				else {
					if (result > change_cnt)
						result = change_cnt;
				}
				break;
			} else if (num_cnt > k) {
				change_cnt -= trial * (num_cnt - k);
				if (result == -1) {
					result = change_cnt;
				} else {
					if (result > change_cnt) {
						result = change_cnt;
					}
				}
				break;
			}
		
		}
	}
	cout << result << '\n';
	return 0;
}
