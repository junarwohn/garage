#include <iostream>

int main(void) {
    char str[81];
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        char pre_O = 0;
        int incre = 0;
        int result = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'O') {
                result += ++incre;
            } else {
                incre = 0;
            }
        }
        std::cout << result << '\n';
    }
    return 0;
}