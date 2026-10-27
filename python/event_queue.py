
from collections import deque

event_queue = deque()

def add_event():
    event = input("Enter event name: ")
    event_queue.append(event)
    print("Event added.")

def process_event():
    if event_queue:
        event = event_queue.popleft()
        print("Processed event:", event)
    else:
        print("No events to process.")

def display_events():
    if event_queue:
        print("Pending events:", list(event_queue))
    else:
        print("No pending events.")

def cancel_event():
    event = input("Enter event to cancel: ")

    if event in event_queue:
        event_queue.remove(event)
        print("Event cancelled.")
    else:
        print("Event not found.")

while True:
    print("\n1. Add Event")
    print("2. Process Next Event")
    print("3. Display Pending Events")
    print("4. Cancel Event")
    print("5. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        add_event()
    elif choice == 2:
        process_event()
    elif choice == 3:
        display_events()
    elif choice == 4:
        cancel_event()
    elif choice == 5:
        break
    else:
        print("Invalid choice!")
