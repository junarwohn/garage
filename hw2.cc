#include <iostream>
#include <cmath>
#include <set>
#define TH 0.0000001
using namespace std;

int g_degree;
double * g_coefficients;
double moment = 0;
/* Setting degree and g_coefficients */
void setup() {
    cout << "Custom coefficient? [y/n]";
    char yn = 'n';
    //cin >> yn;
    if (yn != 'y') {
        g_degree = 4;
        g_coefficients = new double[g_degree + 1];
        g_coefficients[0] = 5;
        g_coefficients[1] = -22.4;
        g_coefficients[2] = 15.85272;
        g_coefficients[3] = 24.161472;
        g_coefficients[4] = -23.4824832;
    } else {
        cout << "Type the degree of polynomial equation" << "\n";
        cin >> g_degree;
        if (g_degree < 0) {
            cout << "Wrong input. Degree must be non-negative";
        }
        g_coefficients = new double[g_degree + 1];

        cout << "Type the g_coefficients. Descent order" << "\n";
        for (int i = 0; i < g_degree + 1; ++i) {
            cin >> g_coefficients[i];
        }
    }
    cout << "f(x) = ";
    cout << g_coefficients[0] << "x^" << g_degree << " ";
    for (int i = 1; i < g_degree; ++i) {
        if (g_coefficients[i] > 0) cout << "+";
        cout << g_coefficients[i] << "x^" << g_degree - i << " ";
    }
    if (g_coefficients[g_degree] > 0) cout << "+";
    cout << g_coefficients[g_degree];
    cout << "\n";
}

double get_val(double * func, double degree, double x) {
    double result = 0;
    for (int i = 0; i < degree + 1; ++i) {
        result *= x;
        result += func[i];
    }
    return result;
}

void derivative(double * func, int degree, double * ret) {
   for (int i = 0 ; i < degree; ++i){
       ret[i] = func[i] * (degree - i);
   } 
}

double derivative_approximate(double * func, int degree, double x) {
    return (get_val(func, degree, x + 0.0001) - get_val(func, degree, x)) / 0.0001;
}

double calculate(double x) {
    double result = 0;
    for (int i = 0; i < g_degree + 1; ++i) {
        result *= x;
        result += g_coefficients[i];
    }
    return result;
}

double newton_method_derivate(double * diff1, double * diff2, double x) {
    double x_new = x - (get_val(diff1, g_degree - 1, x) / get_val(diff2, g_degree - 2, x));
    if ((abs((x_new - x) / x_new)) < TH) {
        return x_new;
    }
    return newton_method_derivate(diff1, diff2, x_new);
}

double newton_method_approximate(double * func, double degree, double x) {
    double h = 0.0001;
    double x_new = x;
    double x_old, f_xi1, f_xi, f_xi_1, mod;
    do {
        x_old = x_new;
        f_xi1 = get_val(func, degree, x_old + h);
        f_xi = get_val(func, degree, x_old);
        f_xi_1 = get_val(func, degree, x_old - h);
        mod = f_xi1 - 2 * f_xi + f_xi_1;
        x_new = x_old -  h * (f_xi1 - f_xi) / mod;
    } while (abs((x_new - x_old) / x_new) > 0.001);
    return x_new;
}

int main(void) {
    setup();
    double * diff1 = new double[g_degree];
    double * diff2 = new double[g_degree - 1];
    set<double> result_set;
    double result;
    cout << "===Newton Method Derivate===";
    cout << "\n";
    derivative(g_coefficients, g_degree, diff1);
    derivative(diff1, g_degree - 1, diff2);
    for (double i = -1000; i < 1000; i+=0.001) {
        result = newton_method_derivate(diff1, diff2, i);
        if (abs(get_val(diff1, g_degree - 1,result)) < 0.00001) {
            if (get_val(diff1, g_degree - 1,result - 0.001) < 0 && get_val(diff1, g_degree - 1,result + 0.001) > 0)
                result_set.insert(round(result * 1000) / 1000);
        }
    }
    for (set<double>::iterator iter = result_set.begin(); iter != result_set.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
    result_set.clear();

    cout << "===Newton Method Approximative===";
    cout << "\n";
    double val;
    for (double i = -1000; i < 1000; i+=0.001) {
        result = newton_method_approximate(g_coefficients, g_degree, i);
        val = abs(get_val(diff1, g_degree - 1, result));
        if (val < 0.01) {
            if (derivative_approximate(g_coefficients, g_degree, result - 0.001) < 0 && derivative_approximate(g_coefficients, g_degree, result + 0.001) > 0 )
                result_set.insert(round(result * 1000) / 1000);
        }
    }
    for (set<double>::iterator iter = result_set.begin(); iter != result_set.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
    result_set.clear();

    return 0;
}
