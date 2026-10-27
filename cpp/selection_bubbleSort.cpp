
#include <iostream>
#include <iomanip>
using namespace std;

// Selection Sort
void selectionSort(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    double salaries[] = {
        45000.75, 52000.0, 39000.3, 61000.8,
        47000.25, 88000.0, 73000.45, 59000.1
    };

    int n = 8, choice;

    cout << fixed << setprecision(2);

    // Original salaries
    cout << "Original salaries:\n";
    for (int i = 0; i < n; i++)
        cout << salaries[i] << " ";

    cout << "\n\n1. Selection Sort";
    cout << "\n2. Bubble Sort";
    cout << "\nChoose sorting method: ";
    cin >> choice;

    if (choice == 1)
        selectionSort(salaries, n);
    else if (choice == 2)
        bubbleSort(salaries, n);
    else {
        cout << "Invalid choice!";
        return 0;
    }

    // Sorted salaries
    cout << "\n\nSorted salaries:\n";
    for (int i = 0; i < n; i++)
        cout << salaries[i] << " ";

    // Top five highest salaries
    cout << "\n\nTop 5 highest salaries:\n";

    for (int i = n - 1; i >= n - 5; i--)
        cout << salaries[i] << endl;

    return 0;
}
