#include <iostream>
using namespace std;
int main(void) {
	int N = 0, input = 0;
	long int result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N * N; i++) {
		scanf("%d", &input);
		result += input;
	}
	cout << result;
}
