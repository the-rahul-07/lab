
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n1.Insert  2.Search  3.Delete";
        cout << "\n4.Inorder  5.Preorder  6.Postorder  7.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
        }
        else if (choice == 2) {
            cout << "Enter value to search: ";
            cin >> value;

            if (search(root, value))
                cout << "Element found\n";
            else
                cout << "Element not found\n";
        }
        else if (choice == 3) {
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
        }
        else if (choice == 4) {
            inorder(root);
            cout << endl;
        }
        else if (choice == 5) {
            preorder(root);
            cout << endl;
        }
        else if (choice == 6) {
            postorder(root);
            cout << endl;
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
