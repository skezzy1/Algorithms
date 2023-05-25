#include <iostream>
using namespace std;

int main() {
    int** a, n, i, j;
    cout << "Input n: "; cin >> n;
    cout << "Matrix A(n*n): " << endl;
    a = new int* [n];
    for (i = 0; i < n; i++) a[i] = new int[n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) cin >> a[i][j];
    cout << endl;
    //змійка
    for (j = 0; j < n; j++) {
        if (j % 2 == 0) {
            for (i = n - 1; i >= 0; i--)
                cout << a[i][j] << " ";
        }
        else {
            for (i = 0; i < n; i++)
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //в рядок
    for (j = 0; j < n; j++) {
        if (j % 2 == 0) {
            for (i = n - 1; i >= 0; i--)
                cout << a[i][j] << " ";
        }
        else {
            for (i = 0; i < n; i++)
                cout << a[i][j] << " ";
        }
    }
    cout << "\n\n";
    //------------------------------------------
    for (j = 0; j < n; j++) {
        if (j % 2 == 0) {
            for (i = n - 1; i >= 0; i--)
                cout << "(" << j << "," << i << "): " << a[i][j] << " ";
            cout << endl;
        }
        else {
            for (i = 0; i < n; i++)
                cout << "(" << j << "," << i << "): " << a[i][j] << " ";
        }
    }
    //----------------------------------------
    for (i = 0; i < n; i++) delete[] a[i];
    delete[] a;
    return 0;
}