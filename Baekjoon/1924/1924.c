#include <stdio.h>
int main(void) {
		int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
		int m, d;
		scanf("%d %d", &m, &d);
		int days = 0;
		for (int i = 0; i < m - 1; i++) {
				days += month[i];
		}
		days += d;
		printf("%s", day[days%7]);
		return 0;
}
