#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		char input_str[31];
		cin >> input_str;
		for (int l = 1; l <= 10; l++) {
			bool check = true;
			for (int c = 0; c < l; c++) {
				char cmp = input_str[c];
				for (int t = 1; t < 30 / l; t++)
					if (cmp != input_str[c + l * t])
						check = false;
				if (!check)
					break;
			}
			if (check) {
				printf("#%d %d\n", i + 1, l);
				break;
			}
		}
	}
	return 0;
}
