
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll_no;
    string name;
    float marks;
    Node* next;
};

Node* head = NULL;

// Add student
void addStudent() {
    Node* newNode = new Node;

    cout << "Enter roll no: ";
    cin >> newNode->roll_no;
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter marks: ";
    cin >> newNode->marks;

    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display students
void display() {
    if (head == NULL) {
        cout << "No records found\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->roll_no << " "
             << temp->name << " "
             << temp->marks << endl;
        temp = temp->next;
    }
}

// Search student
void searchStudent() {
    int roll_no;
    cout << "Enter roll no: ";
    cin >> roll_no;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll_no == roll_no) {
            cout << temp->roll_no << " "
                 << temp->name << " "
                 << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

// Delete student
void deleteStudent() {
    int roll_no;
    cout << "Enter roll no: ";
    cin >> roll_no;

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->roll_no != roll_no) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student not found\n";
    } else {
        if (previous == NULL)
            head = current->next;
        else
            previous->next = current->next;

        delete current;
        cout << "Student deleted\n";
    }
}

// Update student
void updateStudent() {
    int roll_no;
    cout << "Enter roll no: ";
    cin >> roll_no;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll_no == roll_no) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new marks: ";
            cin >> temp->marks;
            cout << "Student updated\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

// Sort students
void sortStudents() {
    int field, order;

    cout << "Sort by: 1. Roll No  2. Marks: ";
    cin >> field;
    cout << "Order: 1. Ascending  2. Descending: ";
    cin >> order;

    if ((field != 1 && field != 2) ||
        (order != 1 && order != 2)) {
        cout << "Invalid choice\n";
        return;
    }

    for (Node* current = head; current != NULL; current = current->next) {
        for (Node* temp = current->next; temp != NULL; temp = temp->next) {
            bool swapNeeded;

            if (field == 1)
                swapNeeded = (order == 1)
                    ? current->roll_no > temp->roll_no
                    : current->roll_no < temp->roll_no;
            else
                swapNeeded = (order == 1)
                    ? current->marks > temp->marks
                    : current->marks < temp->marks;

            if (swapNeeded) {
                swap(current->roll_no, temp->roll_no);
                swap(current->name, temp->name);
                swap(current->marks, temp->marks);
            }
        }
    }

    cout << "Records sorted\n";
    display();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Update Student";
        cout << "\n4. Search Student";
        cout << "\n5. Sort Students";
        cout << "\n6. Display Students";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: sortStudents(); break;
            case 6: display(); break;
            case 7: cout << "Exiting\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
