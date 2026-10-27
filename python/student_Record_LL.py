
class Node:
    def __init__(self, roll_no, name, marks):
        self.roll_no = roll_no
        self.name = name
        self.marks = marks
        self.next = None

head = None

def add_student():
    global head
    roll_no = int(input("Enter roll no: "))
    name = input("Enter name: ")
    marks = float(input("Enter marks: "))
    new_node = Node(roll_no, name, marks)

    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node

def display():
    if head is None:
        print("No records found")
        return

    temp = head
    while temp:
        print(temp.roll_no, temp.name, temp.marks)
        temp = temp.next

def search_student():
    roll_no = int(input("Enter roll no: "))
    temp = head
    while temp:
        if temp.roll_no == roll_no:
            print(temp.roll_no, temp.name, temp.marks)
            return
        temp = temp.next
    print("Student not found")

def delete_student():
    global head
    roll_no = int(input("Enter roll no: "))
    current = head
    previous = None

    while current and current.roll_no != roll_no:
        previous = current
        current = current.next

    if current is None:
        print("Student not found")
    elif previous is None:
        head = current.next
    else:
        previous.next = current.next

def update_student():
    roll_no = int(input("Enter roll no: "))
    temp = head
    while temp:
        if temp.roll_no == roll_no:
            temp.name = input("Enter new name: ")
            temp.marks = float(input("Enter new marks: "))
            print("Student updated")
            return
        temp = temp.next
    print("Student not found")

def sort_students():
    field = input("Sort by roll_no or marks: ").lower()
    order = input("Ascending or descending (a/d): ").lower()

    if field not in ("roll_no", "marks") or order not in ("a", "d"):
        print("Invalid choice")
        return

    current = head
    while current:
        temp = current.next
        while temp:
            value1 = current.roll_no if field == "roll_no" else current.marks
            value2 = temp.roll_no if field == "roll_no" else temp.marks

            if (order == "a" and value1 > value2) or \
               (order == "d" and value1 < value2):
                current.roll_no, temp.roll_no = temp.roll_no, current.roll_no
                current.name, temp.name = temp.name, current.name
                current.marks, temp.marks = temp.marks, current.marks
            temp = temp.next
        current = current.next
    display()

while True:
    print("\n1. Add  2. Delete  3. Update")
    print("4. Search  5. Sort  6. Display  7. Exit")
    choice = int(input("Enter choice: "))

    if choice == 1:
        add_student()
    elif choice == 2:
        delete_student()
    elif choice == 3:
        update_student()
    elif choice == 4:
        search_student()
    elif choice == 5:
        sort_students()
    elif choice == 6:
        display()
    elif choice == 7:
        break
    else:
        print("Invalid choice")
