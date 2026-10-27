
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> events;

// Add an event
void addEvent() {
    string event;
    cout << "Enter event name: ";
    cin >> event;

    events.push(event);
    cout << "Event added.\n";
}

// Process the next event
void processEvent() {
    if (events.empty()) {
        cout << "No events to process.\n";
        return;
    }

    cout << "Processed event: " << events.front() << endl;
    events.pop();
}

// Display pending events
void displayEvents() {
    if (events.empty()) {
        cout << "No pending events.\n";
        return;
    }

    queue<string> temp = events;

    cout << "Pending events: ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

// Cancel an event
void cancelEvent() {
    string event;
    cout << "Enter event to cancel: ";
    cin >> event;

    queue<string> temp;
    bool found = false;

    while (!events.empty()) {
        if (events.front() == event && !found) {
            found = true;
        } else {
            temp.push(events.front());
        }
        events.pop();
    }

    events = temp;

    if (found)
        cout << "Event cancelled.\n";
    else
        cout << "Event not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Event";
        cout << "\n2. Process Next Event";
        cout << "\n3. Display Pending Events";
        cout << "\n4. Cancel Event";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEvent(); break;
            case 2: processEvent(); break;
            case 3: displayEvents(); break;
            case 4: cancelEvent(); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
