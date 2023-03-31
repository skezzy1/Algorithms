#include <iostream>

using namespace std;
//
//double a(int i)
//{
//  if (i == 0 || i == 1)
//  {
//    return 1;
//  }
//  return a(i - 2) + (a(i - 1) / pow(2, i - 1));
//}

double limit_precision(double x) {
    return round(x * 1000000) / 1000000;
}

int main()
{
    //double product =1;
    //for (int i = 2; i <= 14; i++)
    //{
    //  product *= a(i);
    //  cout << product << endl;
    //}

    double product = 1; int k = 1;
    double n = sqrt(2) / 2;
    n = limit_precision(n);
    while (product != n)
    {
        product *= 1 + (pow(-1, k) / (2 * k + 1));
        product = limit_precision(product);
        cout << product << "  :  " << k << endl;
        k++;
    }
}