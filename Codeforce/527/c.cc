#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <windows.h>

using namespace std;

bool compare(const string &s1, const string &s2) {
	if (s1.length() < s2.length()) {
		return false;
	} else {
		return true;
	}
}

string search_f(string result_str, string * input_list, int index_of_candi, int max) {
	if(index_of_candi >= max) {
		return result_str;
	}
	/*
	bool is_complete = true;
	for(int i = 0; i < result_str.length();i++) {
		if(result_str[i] == '0') {
			is_complete = false;
			break;
		}
	}
	if(is_complete) {
		return result_str;
	}
	*/
	string candi_str = input_list[index_of_candi];
	string tmp_result_str = result_str;
	bool checker = true;
	//if pre
	for(int i = 0; i < candi_str.length(); i++) {
		if(tmp_result_str[i] != candi_str[i]) {
			if (tmp_result_str[i] == '0') {
				tmp_result_str[i] = candi_str[i];
			} else {
				checker = false;
				break;
			}
		}
	}
	if(checker) {
		result_str = tmp_result_str;
		cout << 'P';
	} else {
		//if sub
		for(int i = result_str.length() - 1; i > result_str.length() - candi_str.length(); i--) {
			result_str[i] = candi_str[i];
		}
		cout << 'S';
	}
	//cout << result_str;
	//Sleep(1);
	return search_f(result_str, input_list, ++index_of_candi, max);
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string * input_list = new string[2 * n - 2];
	for(int i = 0; i < 2 * n - 2; i++) {
		cin >> input_list[i];
	}
	sort(input_list, input_list + 2 * n - 2, compare);
	string result_str;
	result_str.resize(n, '0');
	search_f(result_str, input_list, 0, 2*n - 2);
	return 0;
}

