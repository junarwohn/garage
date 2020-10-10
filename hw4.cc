#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <opencv2/opencv.hpp>
// #include <vector>

using namespace std;

double calculate(double * coefficients, int degree, int x) {
    double result = 0;
    for (int i = 0; i < degree + 1; ++i) {
        result *= x;
        result += coefficients[i];
    }
    return result;
}

int main(void) {
    // random
    random_device rd;
    mt19937 gen(rd());
    // mt19937 gen(time(NULL));

    uniform_int_distribution<int> dist(0, 8);

    double coefficients[3] = {1, 1, 1};
    double points_2d[][2] = {
        {-2.9, 35.4}, 
        {-2.1, 19.7},
        {-0.9, 5.7}, 
        {1.1,  2.1}, 
        {0.1,  1.2}, 
        {1.9, 8.7}, 
        {3.1, 25.7}, 
        {4.0, 41.5}
    };
    bool random_points[8];

    for (int i = 0; i < 8; ++i) {
        cout << dist(gen);
        // cout << random_points[i];
        // cout << points_2d[i][1] << " " << points_2d[i][1] << '\n';
    }
    return 0;
}