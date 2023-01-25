#include <iostream>
using namespace std;
int main(void) {
	int q, a, b;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		printf("#%d %d %d\n", i + 1, a / b, a % b);
	}
	return 0;
}
			
