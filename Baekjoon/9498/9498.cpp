#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    if (N >= 90 && N <= 100) {
        cout << 'A';
    } else if (N >= 80 && N < 90) {
        cout << 'B';
    } else if (N >= 70 && N < 80) {
        cout << 'C';
    } else if (N >= 60 && N < 70) {
        cout << 'D';
    } else {
        cout << 'F';
    };
}