#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
/*
bool is_in(set<int> list, int x) {
	bool ret = false;
	for (set<int>::iterator i = list.begin(); i != list.end(); ++i) {
		if (*i == x) {
			ret = true;
			break;
		}
	}
	return ret;
}
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int * input_list = new int[n];
	long long int sum = 0;
	set<int> s; 
	for (int i = 0; i < n; i++) {
		cin >> input_list[i];
		s.insert(input_list[i]);
		sum += input_list[i];
	}
	set<int> remove_list;
	int remove_cnt = 0;
	for (set<int>::iterator s_iter = s.begin(); s_iter != s.end(); ++s_iter) {
		int target = sum - 2 * (* s_iter);
		if (s.find(target) != s.end() && s.count(target) > 1) {
			remove_list.insert(target);
		}
	}
	for (int i = 0; i < n; i++) {
		if (remove_list.find(input_list[i]) != remove_list.end()) {
			remove_cnt++;
		}
	}
	cout << remove_cnt << '\n';
	for (int i = 0; i < n; i++) {
		if (remove_list.find(input_list[i]) != remove_list.end()) {
			cout << i + 1 << ' ';
		}
	}
	return 0;
}
