#include <iostream>
#include <algorithm>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int * a = new int[n];
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[i] = tmp;
	}
	int row = 19, col = 200001;
	int** divide_list = new int* [19];
	for (int i = 0; i < 19; i++) {
		divide_list[i] = new int[200001];
		for (int j = 0; j < 200001; j++)
			divide_list[i][j] = 0;
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		divide_list[0][a[i]]++;
		if (a[i] > max)
			max = a[i];
	}
	cout << max;
	int search_max = max;
	for (int trial = 1; trial < 19; trial++) {
		for (int num = 1; num <= search_max; num++) {
			divide_list[trial][num / 2] = divide_list[trial - 1][num];
		}
		search_max /= 2;
	}
	bool is_searched = false;
	for (int search_num = max; search_num >= 0; search_num--) {
		int num_cnt = 0;
		int change_cnt = 0;
		for (int trial = 0; trial < 19; trial++) {
			num_cnt += divide_list[trial][search_num];
			if (num_cnt == k) {
				change_cnt += trial * divide_list[trial][search_num];
				cout << change_cnt << '\n';
				is_searched = true;
				break;
			} else if (num_cnt > k) {
				change_cnt += trial * (k - num_cnt + divide_list[trial][search_num]);
				cout << change_cnt << '\n';
				is_searched = true;
				break;
			}
		}
		if (is_searched)
			break;
	}
	return 0;
}
