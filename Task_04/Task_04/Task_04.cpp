#include <iostream>
#include <vector>

using namespace std;

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    // Зчитування масиву та числа s
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Пошук найдовшої підпослідовності з сумою цифр s
    int start_index = 0;
    int end_index = -1;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += sum_of_digits(a[j]);
            if (sum == s && j - i + 1 > max_length) {
                max_length = j - i + 1;
                start_index = i;
                end_index = j;
            }
        }
    }

    // Виведення результату
    if (max_length > 0) {
        cout << "Longest subsequence with sum of digits equal to " << s << ": ";
        for (int i = start_index; i <= end_index; i++) {
            cout << a[i] << " ";
        }
        cout << "(indices " << start_index << " to " << end_index << ")" << endl;
    }
    else {
        cout << "There is no subsequence with sum of digits equal to " << s << endl;
    }

    return 0;
}