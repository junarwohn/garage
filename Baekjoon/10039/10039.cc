#include <iostream>

int main(void) {
    int input_set[5] = {0,};
    int result = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> input_set[i];
        if (input_set[i] < 40) {
            input_set[i] = 40;
        }
        result += input_set[i];
    }
    std::cout << result/5 << '\n';
    return 0;
}