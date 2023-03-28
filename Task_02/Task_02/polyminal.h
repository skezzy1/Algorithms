#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polynomial {
private:
    vector<int> coeffs;
public:
    Polynomial(); // за замовчуванням
    Polynomial(vector<int> coeffs);
    friend istream& operator>>(istream& is, Polynomial& p);
    friend ostream& operator<<(ostream& os, const Polynomial& p);
    Polynomial operator+(const Polynomial& other);
    Polynomial operator-(const Polynomial& other);
    Polynomial operator*(Polynomial& other);
    Polynomial differentiate();
    void result();
};
