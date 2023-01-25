#include <iostream>
#include <set>
#define TH 0.0000001
using namespace std;


int degree;
double * coefficients;

/* Setting degree and coefficients */
void setup() {
    cout << "Custom coefficient? [y/n]";
    char yn = 'n';
    //cin >> yn;
    if (yn != 'y') {
        degree = 4;
        coefficients = new double[++degree];
        coefficients[0] = 5;
        coefficients[1] = -22.4;
        coefficients[2] = 15.85272;
        coefficients[3] = 24.161472;
        coefficients[4] = -23.4824832;
    } else {
        cout << "Type the degree of polynomial equation" << "\n";
        cin >> degree;
        if (degree < 0) {
            cout << "Wrong input. Degree must be non-negative";
        }
        coefficients = new double[++degree];

        cout << "Type the coefficients. Descent order" << "\n";
        for (int i = 0; i < degree; i++) {
            cin >> coefficients[i];
        }
    }

    cout << "f(x) = ";
    cout << coefficients[0] << "x^" << degree - 1 << " ";
    for (int i = 1; i < degree - 1; i++) {
        if (coefficients[i] > 0) cout << "+";
        cout << coefficients[i] << "x^" << degree - i - 1 << " ";
    }
    if (coefficients[degree - 1] > 0) cout << "+";
    cout << coefficients[degree - 1];
    cout << "\n";
}

double round(double x) {
    int r = x * 10000;
    if (r % 10 > 5) {
        r += 1;
    }
    return ((double) r) / 10000;
}

double calculate(double x) {
    round(12);
    long double result = 0;
    for (int i = 0; i < degree; i++) {
        result *= x;
        result += coefficients[i];
    }
    return (double) result;
}

double bisection(double lb, double ub) {
    //cout << lb << ", " << ub << "\n";
    double mid = (lb + ub) / 2;
    if ((ub - mid) < TH)
        return mid;
    return calculate(mid) * calculate(lb) > 0 ? bisection(mid, ub) : bisection(lb, mid);
}

double newton_raphson(double x) {
    double old_y = calculate(x);
    /* Scant Method */
    double gradient = (calculate(x + 0.000001) - old_y) / 0.000001;
    double x_new = x - old_y / gradient;
    if ((abs(x_new - x) / x_new) < TH) {
        return x_new;
    }
    return newton_raphson(x_new);
}


int main(void) {
    setup();
    cout << "===Bisection Method===";
    cout << "\n";
    set<double> result_set;
    for (double i = -1000; i < 1000; i+=0.001) {
        if (calculate(i) * calculate(i + 1) < 0) {
            i = round(bisection(i, i+1));
            result_set.insert(i);
            i -= 0.0009;
        }
    }
    for (set<double>::iterator iter = result_set.begin(); iter != result_set.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
    result_set.clear();

    cout << "===Newton-Raphson Method===";
    cout << "\n";
    double result;
    for (double i = -1000; i < 1000; i+=0.001) {
        result = newton_raphson(i);
        if (abs(calculate(result)) < TH) {
            result_set.insert(round(result));
        }
    }
    for (set<double>::iterator iter = result_set.begin(); iter != result_set.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
    return 0;
};