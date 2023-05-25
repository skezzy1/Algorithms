#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
void processNumbers(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    queue<int> perfectSquares;
    queue<int> negativeNumbers;
    queue<int> otherNumbers;

    int number;
    while (file >> number) {
        if (number >= 0 && sqrt(number) == floor(sqrt(number))) {
            perfectSquares.push(number);
        }
        else if (number < 0) {
            negativeNumbers.push(number);
        }
        else {
            otherNumbers.push(number);
        }
    }

    cout << "Perfect squares: ";
    while (!perfectSquares.empty()) {
        cout << perfectSquares.front() << " ";
        perfectSquares.pop();
    }

    cout << "\nNegative numbers: ";
    while (!negativeNumbers.empty()) {
        cout << negativeNumbers.front() << " ";
        negativeNumbers.pop();
    }

    cout << "\nOther numbers: ";
    while (!otherNumbers.empty()) {
        cout << otherNumbers.front() << " ";
        otherNumbers.pop();
    }

    file.close();
}

int main() { 
    string filename = "numbers.txt";
    try {
        cout << "Спроба відкрити файл!" << endl;
        comp1.open(filename);
        cout << "Файл успішно відкритий!" << endl;
    }
    catch (const ifstream::failure& ex) {
        cout << ex.what() << endl;
        cout << ex.code() << endl;
        cout << "Помилка відкриття файлу!" << endl;
    }
    processNumbers(filename);
    return 0;
}