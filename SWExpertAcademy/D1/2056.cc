#include <iostream>
using namespace std;
int MON[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int q;
	cin >> q;
	char input_date[9];
	int year, month, day;
	for (int i = 0; i < q; i++) {
		cin >> input_date;
		for (int c = 0; c < 8; c++) 
			input_date[c] -= '0';
		year = (int) (1000 * input_date[0] + 100 * input_date[1] + 10 * input_date[2] + input_date[3]);
		month = (int) (10 * input_date[4] + input_date[5]);
		day = (int) (10 * input_date[6] + input_date[7]);
		if (year >= 0 && month > 0 && month <= 12 && day > 0 && MON[month - 1] >= day)
			printf("#%d %04d/%02d/%02d\n", i + 1, year, month, day);
		else
			printf("#%d -1\n", i + 1);
	}
	return 0;
}

