
#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];
int status[SIZE] = {0}; // 0 = empty, 1 = occupied, 2 = deleted

int hashFunction(int key) {
    return key % SIZE;
}

// Insert key
void insert(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 1 && table[pos] == key) {
            cout << "Key already exists\n";
            return;
        }

        if (status[pos] != 1) {
            table[pos] = key;
            status[pos] = 1;
            cout << "Key inserted\n";
            return;
        }
    }

    cout << "Hash table is full\n";
}

// Search key
void search(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0) {
            cout << "Key not found\n";
            return;
        }

        if (status[pos] == 1 && table[pos] == key) {
            cout << "Key found at index " << pos << endl;
            return;
        }
    }

    cout << "Key not found\n";
}

// Delete key
void deleteKey(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0) {
            cout << "Key not found\n";
            return;
        }

        if (status[pos] == 1 && table[pos] == key) {
            status[pos] = 2;
            cout << "Key deleted\n";
            return;
        }
    }

    cout << "Key not found\n";
}

// Display table
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        if (status[i] == 1)
            cout << table[i];
        else
            cout << "Empty";

        cout << endl;
    }
}

int main() {
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete";
        cout << "\n4. Display\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                insert(key);
                break;

            case 2:
                cout << "Enter key: ";
                cin >> key;
                search(key);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
