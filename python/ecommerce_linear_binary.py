# Customer Account ID Search

ids = [101, 205, 310, 415, 520, 625]

print("1. Linear Search")
print("2. Binary Search")

choice = int(input("Choose search method (1 or 2): "))
key = int(input("Enter customer ID to search: "))

if choice == 1:
    # Linear Search
    found = False

    for i in range(len(ids)):
        if ids[i] == key:
            found = True
            break

    if found:
        print("ID found using Linear Search")
    else:
        print("ID not found using Linear Search")

elif choice == 2:
    # Binary Search
    low = 0
    high = len(ids) - 1
    found = False

    while low <= high:
        mid = (low + high) // 2

        if ids[mid] == key:
            found = True
            break
        elif ids[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    if found:
        print("ID found using Binary Search")
    else:
        print("ID not found using Binary Search")

else:
    print("Invalid choice!")
