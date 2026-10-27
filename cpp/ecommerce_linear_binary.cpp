
#include <iostream>
using namespace std;

int main() {
    int ids[] = {101, 205, 310, 415, 520, 625};
    int n = 6, key, choice;
    bool found = false;

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nChoose search method: ";
    cin >> choice;

    cout << "Enter customer ID: ";
    cin >> key;

    if (choice == 1) {
        // Linear Search
        for (int i = 0; i < n; i++) {
            if (ids[i] == key) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "ID found using Linear Search";
        else
            cout << "ID not found using Linear Search";
    }
    else if (choice == 2) {
        // Binary Search
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (ids[mid] == key) {
                found = true;
                break;
            }
            else if (ids[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (found)
            cout << "ID found using Binary Search";
        else
            cout << "ID not found using Binary Search";
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}
