#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
    int N;
    float * f_list = new float(N);
    int * cnt_list = new int(N);
    char s[1000];
    char n_s[1000];
    char * pch;

    cin >> N;
    fgets(s, 1000, stdin);
    cout << s;
//    for (int i = 0; i < N; i++) {
//        cnt_list[i] = 0;
//        f_list[i] = (1.0 / N) * (i + 1);
//        cout << f_list[i] << endl;
//    }
//    cout << s << endl;
//    pch = strtok(s, " ");
//    while (pch != NULL) {
//        for (int j = 0; j < N; j++) {
//            if (stof(pch) < f_list[j]) {
//                cout << stof(pch) << " : " << f_list[j] << endl;
//                cnt_list[j]++;
//                break;
//            }
//        }
//        cout << pch << endl;
//        pch = strtok(NULL, " ");
//    }
//    for (int i = 0; i < N; i++) {
//        cout << cnt_list[i] << " ";
//    }
//    delete []f_list;
//    delete []cnt_list;
//    return 0;
}