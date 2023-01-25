//
// Created by Wohn on 2017-10-10.
//

#include <iostream>
using namespace std;
int main(void) {
    char radio[201] = {0,};
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        radio[0] = '\0';
        cin >> radio;
        int index = 0;
        // first exception handling
//        while(radio[index] != '0') {
//            index++;
//        }
        if (!((radio[index] == '1' && radio[index + 1] == '0') || (radio[index] == '0' && radio[index + 1] == '1'))) {
            cout << "NO" << endl;
            break;
        }
        char is_vega = 1;
        while (radio[index] != '\0') {
            int start_index = index;
            while(1) {
                if (radio[index] == '\0') {
                    is_vega = 0;
                    break;
                } else if (radio[index] == '0') {
                    break;
                }
                index++;
            }
            if (index >= start_index + 1 && radio[index + 1] == '0') { // 1 + 0 * (2 + n) + 1 * (1 + m + k) pattern
                while (radio[index] != '1' && radio[index] != '\0') {
                    index++;
                }
                index++;
            } else if (radio[index + 1] == '1') {
                index++;
            } else {
                is_vega = 0;
                break;
            }
        }
        if (is_vega) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}