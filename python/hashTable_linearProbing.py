
SIZE = 10
table = [None] * SIZE
deleted = "DELETED"

def hash_function(key):
    return key % SIZE

# Insert key
def insert(key):
    index = hash_function(key)

    for i in range(SIZE):
        pos = (index + i) % SIZE

        if table[pos] == key:
            print("Key already exists")
            return

        if table[pos] is None or table[pos] == deleted:
            table[pos] = key
            print("Key inserted")
            return

    print("Hash table is full")

# Search key
def search(key):
    index = hash_function(key)

    for i in range(SIZE):
        pos = (index + i) % SIZE

        if table[pos] is None:
            print("Key not found")
            return

        if table[pos] == key:
            print("Key found at index", pos)
            return

    print("Key not found")

# Delete key
def delete(key):
    index = hash_function(key)

    for i in range(SIZE):
        pos = (index + i) % SIZE

        if table[pos] is None:
            print("Key not found")
            return

        if table[pos] == key:
            table[pos] = deleted
            print("Key deleted")
            return

    print("Key not found")

# Display table
def display():
    for i in range(SIZE):
        print(i, ":", table[i] if table[i] is not None else "Empty")

# Main program
while True:
    print("\n1. Insert")
    print("2. Search")
    print("3. Delete")
    print("4. Display")
    print("5. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        key = int(input("Enter key: "))
        insert(key)
    elif choice == 2:
        key = int(input("Enter key: "))
        search(key)
    elif choice == 3:
        key = int(input("Enter key: "))
        delete(key)
    elif choice == 4:
        display()
    elif choice == 5:
        break
    else:
        print("Invalid choice")
