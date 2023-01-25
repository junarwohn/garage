#include <iostream>
#include <algorithm>
using namespace std;

char s[200001], t[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int s_len = 0, t_len = 0, * left, * right;
	char * ps = s, * pt = t;
	while(*(ps++) != '\0') ++s_len;
	while(*(pt++) != '\0') ++t_len;
	left = new int[t_len];
	right = new int[t_len];
	for (int i = 0; i < t_len; ++i) left[i] = 0;
	for (int i = 0; i < t_len; ++i) right[i] = 0;
	// left count
	int j = 0;
	for (int i = 0; i < s_len && j < t_len; ++i) {
		if (s[i] == t[j]) {
			left[j++] = i;
		}
	}
	j = t_len - 1;
	for (int i = s_len - 1; i >= 0 && j >= 0; --i) {
		if (s[i] == t[j]) {
			right[j--] = i;
		}
	}
//	for (int i = 0; i < t_len; i++) cout << left[i] << ' ';
//		cout << '\n';
//	for (int i = 0; i < t_len; i++) cout << right[i] << ' ';
//		cout << '\n';
//	cout << "s_len : " << s_len << " t_len : " << t_len << '\n';
	int result = right[0];
//cout << result << '\n';
	result = max(result, s_len - 1 - left[t_len - 1]);
//cout << result << '\n';
	for (int i = 0; i < t_len - 1; i++) { 
		result = max(result, right[i + 1] - left[i] - 1);
//		cout << result << '\n';
	}
	cout << result;
	return 0;
}

