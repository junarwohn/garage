#include <iostream>

using namespace std;

int main(void) {
    int N,M,K;
    int max_row;
    char input[51];
    int sum_list[51] = {0,};
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0 ; j < M; j++) {
            if (input[j] == '1') 
                sum_list[i]++;
        }
    }
    cin >> K;
    for (max_row = M; max_row > 0; max_row--) {
        if ((M - sum_list[max_row]) <= K)
            break;
    }
    cout << max_row;

}
