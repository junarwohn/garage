#include <iostream>

using namespace std;

int main(void) {
    int input_num = 0;
    cin >> input_num;
    if (input_num < 100) {
        cout << input_num << '\n';
    } else {
        int result = 99;
        for (int i = 100; i <= input_num; i++) {
            if ( (i/100 + i%10) == 2*((i/10) % 10)) {
                result++;
            }
        }
        cout << result << '\n';
    }
    return 0;
}