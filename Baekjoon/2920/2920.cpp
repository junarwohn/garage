#include <iostream>

using namespace std;

int main(void) {
    char * list = new char(8);
    char is_const = 1;
    for (int i = 0; i < 8; i++) {
        cin >> list[i];
    }
    int std_delta = list[1] - list[0];
    for (int j = 1; j < 7; j++) {
        if (std_delta * (list[j+1] - list[j]) <= 0) {
            is_const = 0;
            break;
        }
    }
    if (!is_const) {
        cout << "mixed";
    } else {
        if (std_delta > 0) {
            cout << "ascending";
        } else {
            cout << "descending";
        }
    }
    return 0;
}
