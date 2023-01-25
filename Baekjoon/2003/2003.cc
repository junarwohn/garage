#include <iostream>
using namespace std;

int main(void) {
	int N, M, head = 0, tail = -1, sum = 0, cnt = 0;
	cin >> N >> M;
	int * A = new int[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	while (head < N && tail < N) {
		if (sum < M) {
			sum += A[++tail];
		} else {
			if (sum == M) 
				cnt++;
			sum -= A[head++];
		}
	}
	cout << cnt;
	delete[] A;
	return 0;
}

