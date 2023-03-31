#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x, s, a, eps = 0.0001;
	int k;
	cout << "x = "; cin >> x;
	if (fabs(x) > 1) {
		cout << "Error; Please enter |x| < 1" << endl;
	}
	s = 0; k = 1; a = x;
	while (fabs(a) > eps){
		s += a;
		a *= ((x*x)*(2*k+1)/(2*k+3));
		k++;
	}
	cout << "suma= " << s << "\n";
	cout << "arctg= " << atan(x) << "\n";
	cin.get();
	return 0;
}