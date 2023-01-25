#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int N, M;
		cin >> N >> M;
		int ** flies = new int*[N];
		for (int col = 0; col < N; ++col) {
			flies[col] = new int[N];
			for (int row = 0; row < N; ++row)
				cin >> flies[col][row];
		}
		int max_kill = 0;
		int kill_sum = 0;
		// traverse
		for (int col = 0; col < N - M + 1; ++col) {
			kill_sum = 0;
			for (int c = col; c < col + M - 1; ++c)
				for (int row = 0; row < M; ++row)
					 kill_sum += flies[c][row];
			if (max_kill < kill_sum)
					max_kill = kill_sum;
 			for (int row = 0; row < N - M; ++row) {
				cout << "(" << col << ", " << row << ")\n";
				for (int c = col; c < col + M; ++c) {
					kill_sum -= flies[c][row];
					cout << flies[c][row] << " del" << '\n';
					kill_sum += flies[c][row + M];
					cout << "add " <<  flies[c][row + M] << '\n';
				}
				cout << kill_sum << '\n';
				if (max_kill < kill_sum)
					max_kill = kill_sum;
			}
		}
		cout << '#' << i + 1 << ' ' << max_kill << '\n';
		for (int col = 0; col < N; ++col)
			delete[] flies[col];
		delete[] flies;
	}
	return 0;
}
