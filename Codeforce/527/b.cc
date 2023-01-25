#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int * skill_list = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> skill_list[i];
	}

	sort(skill_list, skill_list + n);
	int total = 0;
	for(int i = 0; i < n; i += 2){
		total += skill_list[i + 1] - skill_list[i];
	}
	cout << total;
	return 0;
}

