
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

def search(root, key):
    if root is None or root.data == key:
        return root
    if key < root.data:
        return search(root.left, key)
    return search(root.right, key)

def display(root):
    if root:
        display(root.left)
        print(root.data, end=" ")
        display(root.right)

def delete(root, key):
    if root is None:
        return root

    if key < root.data:
        root.left = delete(root.left, key)
    elif key > root.data:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left

        temp = root.right
        while temp.left:
            temp = temp.left
        root.data = temp.data
        root.right = delete(root.right, temp.data)

    return root

def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")

root = None

while True:
    print("\n1.Insert  2.Search  3.Delete  4.Inorder")
    print("5.Preorder  6.Postorder  7.Exit")
    choice = int(input("Enter choice: "))

    if choice == 1:
        value = int(input("Enter value: "))
        root = insert(root, value)
    elif choice == 2:
        value = int(input("Enter value to search: "))
        print("Found" if search(root, value) else "Not found")
    elif choice == 3:
        value = int(input("Enter value to delete: "))
        root = delete(root, value)
    elif choice == 4:
        display(root)
        print()
    elif choice == 5:
        preorder(root)
        print()
    elif choice == 6:
        postorder(root)
        print()
    elif choice == 7:
        break
    else:
        print("Invalid choice")
