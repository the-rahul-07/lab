
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string text = "";
stack<string> undoStack, redoStack;

void makeChange() {
    string s;
    cout << "Enter text: ";
    cin >> s;

    undoStack.push(text);
    text += s;

    while (!redoStack.empty())
        redoStack.pop();
}

void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo\n";
        return;
    }

    redoStack.push(text);
    text = undoStack.top();
    undoStack.pop();
}

void redo() {
    if (redoStack.empty()) {
        cout << "Nothing to redo\n";
        return;
    }

    undoStack.push(text);
    text = redoStack.top();
    redoStack.pop();
}

void display() {
    cout << "Document: " << text << endl;
}

int main() {
    int ch;

    do {
        cout << "\n1. Make Change";
        cout << "\n2. Undo";
        cout << "\n3. Redo";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: makeChange(); break;
            case 2: undo(); break;
            case 3: redo(); break;
            case 4: display(); break;
            case 5: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
