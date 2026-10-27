
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;
vector<pair<int, string>> hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, string value) {
    int index = hashFunction(key);

    for (auto &item : hashTable[index]) {
        if (item.first == key) {
            item.second = value;
            cout << "Key updated\n";
            return;
        }
    }

    hashTable[index].push_back({key, value});
    cout << "Inserted successfully\n";
}

void search(int key) {
    int index = hashFunction(key);

    for (auto item : hashTable[index]) {
        if (item.first == key) {
            cout << "Value: " << item.second << endl;
            return;
        }
    }

    cout << "Key not found\n";
}

void deleteKey(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < hashTable[index].size(); i++) {
        if (hashTable[index][i].first == key) {
            hashTable[index].erase(hashTable[index].begin() + i);
            cout << "Deleted successfully\n";
            return;
        }
    }

    cout << "Key not found\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (auto item : hashTable[i])
            cout << "(" << item.first << ", " << item.second << ") ";
        cout << endl;
    }
}

int main() {
    int choice, key;
    string value;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete";
        cout << "\n4. Display\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                insert(key, value);
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
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
