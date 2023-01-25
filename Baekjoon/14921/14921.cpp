#include <iostream>
using namespace std;

int abs(int num) {
    if (num < 0) {
        num = num * -1;
    }
    return num;
}

int main(void) {
    int N = 0;
    cin >> N;
    int * A_list = new int[N];
    for (int i = 0 ; i < N; i++) {
        cin >> A_list[i];
    }
    int left_edge = 0;
    int right_edge = N - 1;
    int total_min = A_list[left_edge] + A_list[right_edge];
    int sub_min = 0;
    while (left_edge < right_edge) {
        sub_min = A_list[left_edge] + A_list[right_edge];
        if (abs(total_min) > abs(sub_min)) {
            total_min = sub_min;
        }
        if (sub_min < 0) {
            left_edge++;
        } else {
            right_edge--;
        }
    }
    cout << total_min;
}
