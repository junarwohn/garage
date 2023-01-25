#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	char * input_arr = new char[n];
	cin >> input_arr;
	int change_cnt = 0;
	for (int i = n - x; i < n; i++)
		if (input_arr[i] == '1')
			change_cnt++;
	if (input_arr[n - y - 1] == '1')
		change_cnt--;
	else
		change_cnt++;
	cout << change_cnt << '\n';
	return 0;
}
