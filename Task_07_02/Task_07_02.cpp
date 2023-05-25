#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cars {
public:
    string name;
    int year;
    double cost;
    Cars() {}
    Cars(string name, int year, double cost) {
        this->name = name;
        this->year = year;
        this->cost = cost;
    }
    string getName() const {
        return name;
    }
    int getYear() const {
        return year;
    }
    double getCost() const {
        return cost;
    }
};

void merge(vector<Cars>& arr, int l, int m, int r, string type) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Cars> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (type == "name") {
            if (L[i].name <= R[j].name) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }
        else if (type == "year") {
            if (L[i].year <= R[j].year) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }
        else if (type == "cost") {
            if (L[i].cost <= R[j].cost) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Cars>& arr, int l, int r, string type) {
    if (l >= r) {
        return;
    }

    int m = (l + r - 1) / 2;

    mergeSort(arr, l, m, type);
    mergeSort(arr, m + 1, r, type);
    merge(arr, l, m, r, type);
}
int binarySearchByScore(vector<Cars>& arr, int score)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].getYear() == score)
            return mid;
        else if (arr[mid].getYear() < score)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<Cars> cars;
    int n;
    cout << "Enter the number of cars: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int year;
        double cost;
        cout << "Enter the name of car " << i + 1 << ": ";
        cin >> name;

        cout << "Enter the year of production of car " << i + 1 << ": ";
        cin >> year;

        cout << "Enter the cost of car " << i + 1 << ": ";
        cin >> cost;

        cars.push_back(Cars(name, year, cost));
    }

    // Запитуємо користувача, за яким критерієм сортувати
    int choice;
    cout << "Sort by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Year of production" << endl;
    cout << "3. Cost" << endl;
    cin >> choice;

    // Викликаємо функцію сортування вибраним критерієм
    switch (choice) {
    case 1:
        mergeSort(cars, 0, cars.size() - 1, "name");
        break;
    case 2:
        mergeSort(cars, 0, cars.size() - 1, "year");
        break;
    case 3:
        mergeSort(cars, 0, cars.size() - 1, "cost");
        break;
    default:
        cout << "Invalid choice. Sorting by name." << endl;
        mergeSort(cars, 0, cars.size() - 1, "name");
        break;
    }
    // Виводимо відсортований список фільмів
    cout << "Sorted list of cars:" << endl;
    for (int i = 0; i < cars.size(); i++) {
        cout << "Car " << i + 1 << ":" << endl;
        cout << "Brand: " << cars[i].getName() << endl;
        cout << "Year of production: " << cars[i].getYear() << endl;
        cout << "Cost: " << cars[i].getCost() << endl;
        cout << endl;
    }
    int searchYear;
    cout << "Enter year of car you want to find:" << endl;
    cin >> searchYear;
    int result = binarySearchByScore(cars, searchYear);
    if (result != -1) {
        cout << cars[result].getName() << endl;
        cout << "Name: " << cars[result].getName() << endl;
        cout << "Year of production: " << cars[result].getYear() << endl;
        cout << "Cost: " << cars[result].getCost() << endl;
    }
    else {
        cout << "Car not found" << endl;

    }
}