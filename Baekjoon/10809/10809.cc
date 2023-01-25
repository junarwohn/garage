#include <iostream>

int main(void) {
    char S[100];
    int check_list['z' - 'a' + 1];
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        check_list[i] = -1;
    }
    std::cin >> S;
    for (int i = 0; S[i] != '\0'; i++) {
        if (check_list[S[i]-'a'] == -1){
            check_list[S[i]-'a'] = i;
        }
    }
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        std::cout << check_list[i] << '\n';
    }
    return 0;
}