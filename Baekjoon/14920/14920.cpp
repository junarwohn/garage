#include <iostream>

using namespace std;

int main(void) {
    int N = 0;
    cin >> N;
    int cnt = 1;
    while (N != 1) {
        if (N%2) {
            N = N * 3 + 1;
        } else {
            N /= 2;
        }
        cnt++;
    }
    cout << cnt;
}