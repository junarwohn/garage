#include <iostream>

using namespace std;

int g_non_self_number_list[10001];
int sum_of_each_pos_number(int n);
void check_non_number(int n);

void check_non_number(int n) {
    int sum = sum_of_each_pos_number(n);
    n += sum;
    if (!g_non_self_number_list[n] || n > 10000) {
        return;
    } else {
        g_non_self_number_list[n] = 0;
        check_non_number(n + sum_of_each_pos_number(n));
    }
}

int sum_of_each_pos_number(int n) {
    int cal = n;
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int main(void) {
    for(int i = 1 ; i <= 10000; i++) {
        g_non_self_number_list[i] = 1;
    }
    for (int i = 1; i <= 10000; i++) {
        check_non_number(i);
    }
    for (int i = 1; i <= 10000; i++) {
        if (g_non_self_number_list[i]) {
            cout << i << '\n';
            // printf("%d\n", i);
        }
    }
    return 0;
}