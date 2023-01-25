#include <iostream>
using namespace std;
char s[200001], t[200001];
char *end_s = s;
int cnt[200001] = {0, };

int sub_search(char * _s, char * _t, char * _left, int len) {
	if (*_t == '\0') {
		int len_front, len_end, max;
		len_front = (_left - s) / sizeof(char);
		len_end = (end_s - _s) / sizeof(char);
		max = len_front > len_end ? len_front : len_end;
		return max > len ? max : len;
	}
	int _cnt = 0;
	while (*_s != *_t && *_s != '\0') {
		_cnt++;
		_s++;
	}
	if (*_s == '\0')
		return -1;
	int next_result, continue_result;
	if (t == _t)
		next_result = sub_search(_s + 1, _t, _s + 1, len);
	else
		next_result = sub_search(_s + 1, _t, _left, len);
	int result = len > _cnt ? len : _cnt;
	continue_result = sub_search(_s + 1, _t + 1, _left, result);
	return next_result > continue_result ? next_result : continue_result;
}
	


int main(void) {
	cin >> s;
	cin >> t;
	while(*(++end_s) != '\0');
//	int s_len = 0;
//	while(s[++s_len] != '\0');
//	int * check_cnt = new int[s_len];
//	char * c = t;
//	int c_cnt = 0;
//	for (int i = 0; i < s_len; i++) {
//		if (*c == s[i])
//			c_cnt++;
//		cnt[i] = c_cnt;
//	}
//	for (int i = 0; i < s_len; i++)
//		cout << cnt[i];
//	cout << '\n';
//	c++;
//	int start_index = 1;
//	for (; *c != '\0'; c++) {
//		c_cnt = 0;
//		for (int i = 0; i < start_index; i++)
//			cnt[i] = 0;
//		for (int i = start_index; i < s_len; i++) {
//			if (*c == s[i] && c_cnt < cnt[i])
//				c_cnt++;
//			cnt[i] = c_cnt;
//		}
//
//		for (int i = 0; i < s_len; i++)
//			cout << cnt[i];
//		cout << '\n';
//		start_index++;
//	}
//	cout << cnt[s_len - 1];
	cout << sub_search(s, t, s, 0);
	return 0;
}




