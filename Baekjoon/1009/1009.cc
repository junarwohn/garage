#include <iostream>
using namespace std;

int main(void) { 
    int testcaseT = 0;
    cin >> testcaseT;
    int a = 0;
    int b = 0;
    int whoseComputer = 1;
    for (int i = 0; i < testcaseT; ++i) {
        cin >> a >> b;
        a %= 10;
        whoseComputer = 1;
        for (int p = 0; p < b; ++p) {
            whoseComputer = (whoseComputer * a) % 10; 
        }
        if (whoseComputer == 0) {
            whoseComputer = 10;    
        }
        cout << whoseComputer << endl;
    }
    return 0;
}