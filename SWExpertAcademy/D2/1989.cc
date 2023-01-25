#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	char str[11];
	cin >> q;
	for (int t = 0; t < q; t++) {
		int str_len = 0;
		cin >> str;
		char * c = str;
		while (*(c++) != '\0') str_len++;
		str_len--;
		bool is_palind = true;
		for (int i = 0; i < (str_len + 1) / 2; i++) {
			if (str[i] != str[str_len - i]) {
				is_palind = false;
				break;
			}
		}

		if (is_palind)
			cout << "#" << t + 1 << " " << 1 << '\n';
		else 
			cout << "#" << t + 1 << " " << 0 << '\n';
	}
	return 0;
}

