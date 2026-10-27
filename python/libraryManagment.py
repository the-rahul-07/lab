
# Library Borrowing Record Manager

library_data = {
    "M001": ["Book A", "Book B"],
    "M002": ["Book C"],
    "M003": [],
    "M004": ["Book A", "Book A"],
    "M005": [],
    "M006": ["Book B", "Book D"]
}

# 1. Average books borrowed
total = 0

for books in library_data.values():
    total += len(books)

average = total / len(library_data)
print("Average books borrowed:", average)

# Count each book
count = {}

for books in library_data.values():
    for book in books:
        if book in count:
            count[book] += 1
        else:
            count[book] = 1

# 2. Most and least borrowed books
most = max(count, key=count.get)
least = min(count, key=count.get)

print("Most borrowed book:", most)
print("Least borrowed book:", least)

# 3. Members who borrowed zero books
zero = 0

for books in library_data.values():
    if len(books) == 0:
        zero += 1

print("Members with zero borrowings:", zero)

# 4. Mode
print("Mode (most borrowed book):", most)
