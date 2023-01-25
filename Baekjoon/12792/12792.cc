#include <iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int * lottery = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		scanf("%d", lottery + i);
	}
	bool is_possible = true;
	for (int i = 1; i <= N; i++) {
		if (i == lottery[i]) {
			cout << "-1";
			is_possible = false;
			break;
		}
	}
	if (is_possible)
		cout << "1000003";
	return 0;
}
