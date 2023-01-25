//
// Created by JoonhoWohn on 2017-11-18.
//

#include <iostream>

using namespace std;

int main(void) {
    int * arr = new int(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                i--;
                break;
            }
        }
    }
    cout << arr[1];
    return 0;
}