#include <iostream>
#include <windows.h>

using namespace std;
int factorial(int m) {
	if (m == 0 || m == 1) {
		return 1;
	}else {
		return m * factorial(m - 1);
	}
}
int formula(int n, int k) {
	return ((factorial(n)) / ((factorial(k) * factorial(n - k))));
}
int main(){
	SetConsoleOutputCP(1251);
	int m, n, result;
	cin >> m >> n;
	if (n >= m) {
		cout << "Не виконана умова n >= m!";
	}
	else {
		result = formula(m, n - 1) + formula(m - 1, n);
		cout << result;
	}
	return 0;
}
