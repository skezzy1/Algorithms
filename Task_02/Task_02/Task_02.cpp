#include <iostream>
#include <vector>
#include <cmath>
#include "polyminal.h"
using namespace std;

int main() {
    Polynomial p1, p2;

    cout << "Enter power of p1:\0"; cin >> p1;
    cout << "Enter power of p2:\0"; cin >> p2;

    cout << "p1: " << p1;
    cout << "p2: " << p2;

    cout << "p1': " << p1.differentiate();
    cout << "p2': " << p2.differentiate();

    cout << "p1 + p2: " << p1 + p2;
    cout << "p1 - p2: " << p1 - p2;
    cout << "p1 * p2: " << p1 * p2;

    (p1 + p2).result();
    (p1 - p2).result();
    (p1 * p2).result();
    (p1.differentiate()).result();
    (p2.differentiate()).result();

    return 0;
}