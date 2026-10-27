
SIZE = 10
hash_table = [[] for i in range(SIZE)]

# Hash function using division method
def hash_function(key):
    return key % SIZE

# Insert key-value pair
def insert(key, value):
    index = hash_function(key)

    for i in range(len(hash_table[index])):
        if hash_table[index][i][0] == key:
            hash_table[index][i] = (key, value)
            print("Key updated")
            return

    hash_table[index].append((key, value))
    print("Inserted successfully")

# Search key
def search(key):
    index = hash_function(key)

    for k, value in hash_table[index]:
        if k == key:
            print("Value:", value)
            return

    print("Key not found")

# Delete key
def delete(key):
    index = hash_function(key)

    for item in hash_table[index]:
        if item[0] == key:
            hash_table[index].remove(item)
            print("Deleted successfully")
            return

    print("Key not found")

# Display hash table
def display():
    for i in range(SIZE):
        print(i, ":", hash_table[i])

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
        value = input("Enter value: ")
        insert(key, value)

    elif choice == 2:
        key = int(input("Enter key to search: "))
        search(key)

    elif choice == 3:
        key = int(input("Enter key to delete: "))
        delete(key)

    elif choice == 4:
        display()

    elif choice == 5:
        break

    else:
        print("Invalid choice")
