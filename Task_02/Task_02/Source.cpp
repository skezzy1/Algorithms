#include <iostream>
#include <vector>
#include <cmath>
#include "polyminal.h"
using namespace std;
Polynomial::Polynomial() {
    vector<int> coeffs = {}; //конструктор за замовчуванням
}
Polynomial::Polynomial(vector<int> coeffs) {
    this->coeffs = coeffs; //доступ до поля private
}
istream& operator>>(istream& is, Polynomial& p) { //перевантаження оператора cin(тимчасовий оператор з яким працюємо, доступ-посилання на private)
    int n; is >> n;
    p.coeffs.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        cout << "Enter num of x^" << i << ": ";
        is >> p.coeffs[i];
    }
    return is;
}
ostream& operator<<(ostream& os, const Polynomial& p) {
    int n = p.coeffs.size() - 1;
    for (int i = n; i >= 0; i--) {
        if (p.coeffs[i] != 0) {
            if (i < n) {
                os << " + ";
            }
            if (i == 0 || p.coeffs[i] != 1) {
                os << p.coeffs[i];
            }
            if (i > 0) {
                os << "x";
            }
            if (i > 1) {
                os << "^" << i;
            }
        }
    }
    os << endl;
    return os;
}

Polynomial Polynomial::operator+(const Polynomial& other) {
    int n = max(coeffs.size(), other.coeffs.size());
    Polynomial result;
    result.coeffs.resize(n);
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        if (i < coeffs.size()) {
            a = coeffs[i]; //coeffs[0] = 8
        }
        if (i < other.coeffs.size()) {
            b = other.coeffs[i];
        }
        result.coeffs[i] = a + b;
    }
    return result;
}


Polynomial Polynomial::operator-(const Polynomial& other) {
    int n = max(coeffs.size(), other.coeffs.size());
    Polynomial result;
    result.coeffs.resize(n);
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        if (i < coeffs.size()) {
            a = coeffs[i];
        }
        if (i < other.coeffs.size()) {
            b = other.coeffs[i];
        }
        result.coeffs[i] = a - b;
    }
    return result;
}

Polynomial Polynomial::operator*(Polynomial& other) {
    int n = coeffs.size(); //4
    int m = other.coeffs.size(); //3
    Polynomial result;
    result.coeffs.resize(n + m - 1); //6
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return result;
}

Polynomial Polynomial::differentiate() {
    int n = coeffs.size() - 1;
    Polynomial result;
    result.coeffs.resize(n);
    for (int i = 0; i < n; i++) {
        result.coeffs[i] = (i + 1) * coeffs[i + 1];
    }
    return result;
}

void Polynomial::result() {
    int x, result = 0; cout << "Enter x: "; cin >> x;
    for (int i = 0; i < coeffs.size(); i++) {
        if (i == coeffs.size()) {
            result += coeffs[i];
            break;
        }
        result = result * x + coeffs[i];

    }
    cout << "Result: " << result << endl;
}