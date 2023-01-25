#include <iostream>

int main(void){
    int N = 0;
    std::cin >> N;
    int * inputList = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> inputList[i];
    }
    int min = inputList[0];
    int max = inputList[0];
    for (int i = 0; i < N; i++) {
        if (min > inputList[i]) {
            min = inputList[i];
        }
        if (max < inputList[i]) {
            max = inputList[i];
        }
    }
    char * checkList = new char[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        checkList[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        checkList[inputList[i] - min] = 1;
    }
    for (int i = 0; i < max - min + 1; i++) {
        if (checkList[i]) {
            std::cout << min + i;
            std::cout << "\n";
        }
    }
    return 0;
}