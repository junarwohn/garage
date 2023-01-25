#include <iostream>
int main(void) {
    int input_num[3] = {0,};
    int num_set[10] = {0,};
    int result = 1;
    std::cin >> input_num[0] >> input_num[1] >> input_num[2];
    for (int i = 0; i < 3; i++) {
        result *= input_num[i];
    }
    int i = 0;
    // std::cout << result << '\n';
    while (result) {
        num_set[result % 10]++;
        result /= 10;
    }
    for (int i = 0; i < 10; i++){
        std::cout << num_set[i] << '\n';
    }
    return 0;
}