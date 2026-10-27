
# Employee Salary Sorting

salaries = [45000.75, 52000.0, 39000.3, 61000.8,
            47000.25, 88000.0, 73000.45, 59000.1]

# Selection Sort
def selection_sort(arr):
    arr = arr.copy()
    n = len(arr)

    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr

# Bubble Sort
def bubble_sort(arr):
    arr = arr.copy()
    n = len(arr)

    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr

# Display top five salaries
def display_top_5(arr):
    print("Top 5 highest salaries:")
    for salary in arr[-5:][::-1]:
        print(f"Rs. {salary:.2f}")

# Main program
print("Original salaries:")
print(salaries)

print("\n1. Selection Sort")
print("2. Bubble Sort")

choice = int(input("Choose sorting method: "))

if choice == 1:
    sorted_salaries = selection_sort(salaries)
elif choice == 2:
    sorted_salaries = bubble_sort(salaries)
else:
    print("Invalid choice!")
    exit()

print("\nSorted salaries:", sorted_salaries)
display_top_5(sorted_salaries)
