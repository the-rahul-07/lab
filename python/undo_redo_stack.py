
class TextEditor:
    def __init__(self):
        self.document = ""
        self.undo_stack = []
        self.redo_stack = []

    # Make a new change
    def make_change(self):
        change = input("Enter text to add: ")
        self.undo_stack.append(self.document)
        self.document += change
        self.redo_stack.clear()
        print("Change added.")

    # Undo the last change
    def undo(self):
        if self.undo_stack:
            self.redo_stack.append(self.document)
            self.document = self.undo_stack.pop()
            print("Undo successful.")
        else:
            print("Nothing to undo.")

    # Redo the undone change
    def redo(self):
        if self.redo_stack:
            self.undo_stack.append(self.document)
            self.document = self.redo_stack.pop()
            print("Redo successful.")
        else:
            print("Nothing to redo.")

    # Display current document
    def display(self):
        print("Current document:", self.document)


# Main program
editor = TextEditor()

while True:
    print("\n1. Make Change")
    print("2. Undo")
    print("3. Redo")
    print("4. Display Document")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        editor.make_change()
    elif choice == 2:
        editor.undo()
    elif choice == 3:
        editor.redo()
    elif choice == 4:
        editor.display()
    elif choice == 5:
        print("Exiting program.")
        break
    else:
        print("Invalid choice!")
