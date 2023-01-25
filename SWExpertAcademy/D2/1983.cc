#include <iostream>
#include <set>
using namespace std;
char GRADE[10][3] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	int N, K;
	for (int t = 0; t < T; ++t) {
		cin >> N >> K;
		float a, b, c;
      		float * score_sum = new float[N];
		for (int i = 0; i < N; ++i) {
			cin >> a >> b >> c;
			score_sum[i] = a * 0.35 + b * 0.45 + c * 0.2;
		}
		set<float> s;
		for (int i = 0; i < N; ++i) {
			s.insert(score_sum[i]);
		}
		set<float>::iterator iter = s.begin();
		while(*iter != score_sum[K - 1]) iter++;
		int rating = N - distance(s.begin(), iter) - 1;
		cout << "#" << t + 1 << " " << GRADE[rating / (N / 10)] << '\n';
	}
	return 0;
}
