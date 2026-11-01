
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    // Insert a new value into the BST
    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(Node* node, int value) {
        if (node == NULL) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    // Display values in ascending order
    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Find the smallest value in a subtree
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    // Delete a value from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Case 1: No child
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }

            // Case 2: Only right child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            // Replace with the in-order successor
            Node* temp = findMin(node->right);

            node->data = temp->data;

            node->right = deleteNode(
                node->right, temp->data
            );
        }

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void sort() {
        inorder(root);
        cout << endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    int values[] = {
        16, 5, 7, 20, 3, 11, 4, 18, 48, 56, 36
    };

    int n = sizeof(values) / sizeof(values[0]);

    // 1. Build the BST
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "Sorted values: ";
    tree.sort();

    // 2. Search for 11
    int key = 11;

    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    }
    else {
        cout << key << " not found in the BST." << endl;
    }

    // 3. Insert 13
    tree.insert(13);

    cout << "After inserting 13: ";
    tree.sort();

    // 4. Delete 20
    tree.remove(20);

    cout << "After deleting 20: ";
    tree.sort();

    return 0;
}



























#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    // Insert a new value into the BST
    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(Node* node, int value) {
        if (node == NULL) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    // Display values in ascending order
    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Pre-order traversal
    void preorder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Post-order traversal
    void postorder(Node* node) {
        if (node == NULL) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Find the smallest value in a subtree
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    // Find the largest value in a subtree
    Node* findMax(Node* node) {
        while (node != NULL && node->right != NULL) {
            node = node->right;
        }

        return node;
    }

    // Delete a value from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Case 1: No child
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }

            // Case 2: Only right child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            // Replace with the in-order successor
            Node* temp = findMin(node->right);

            node->data = temp->data;

            node->right = deleteNode(
                node->right, temp->data
            );
        }

        return node;
    }

    // Delete all nodes
    void deleteTree(Node* node) {
        if (node == NULL) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // Level-order traversal
    void levelOrder() {
        if (root == NULL) {
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Node* temp = queue[front++];

            cout << temp->data << " ";

            if (temp->left != NULL) {
                queue[rear++] = temp->left;
            }

            if (temp->right != NULL) {
                queue[rear++] = temp->right;
            }
        }
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        deleteTree(root);
    }

    void create() {
        int n, value;

        cout << "How many values? ";
        cin >> n;

        if (n < 0 || n > 100) {
            cout << "Invalid number of values." << endl;
            return;
        }

        deleteTree(root);
        root = NULL;

        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        }
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void update(int oldValue, int newValue) {
        if (!search(oldValue)) {
            cout << oldValue << " not found in the BST." << endl;
            return;
        }

        if (oldValue == newValue) {
            cout << "Value is unchanged." << endl;
            return;
        }

        if (search(newValue)) {
            cout << newValue << " already exists in the BST." << endl;
            return;
        }

        root = deleteNode(root, oldValue);
        root = insertNode(root, newValue);

        cout << "Value updated successfully." << endl;
    }

    void sort() {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }

    void displayLevelOrder() {
        levelOrder();
        cout << endl;
    }

    void minNode() {
        if (root == NULL) {
            cout << "BST is empty." << endl;
            return;
        }

        cout << "Minimum node: "
             << findMin(root)->data << endl;
    }

    void maxNode() {
        if (root == NULL) {
            cout << "BST is empty." << endl;
            return;
        }

        cout << "Maximum node: "
             << findMax(root)->data << endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    int values[] = {
        16, 5, 7, 20, 3, 11, 4, 18, 48, 56, 36
    };

    int n = sizeof(values) / sizeof(values[0]);

    // 1. Build the BST
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "Sorted values: ";
    tree.sort();

    // 2. Search for 11
    int key = 11;

    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    }
    else {
        cout << key << " not found in the BST." << endl;
    }

    // 3. Insert 13
    tree.insert(13);

    cout << "After inserting 13: ";
    tree.sort();

    // 4. Delete 20
    tree.remove(20);

    cout << "After deleting 20: ";
    tree.sort();

    cout << "Pre-order traversal: ";
    tree.displayPreorder();

    cout << "Post-order traversal: ";
    tree.displayPostorder();

    cout << "Level-order traversal: ";
    tree.displayLevelOrder();

    tree.minNode();
    tree.maxNode();

    cout << "Updating 11 to 14: ";
    tree.update(11, 14);

    cout << "After updating: ";
    tree.sort();

    return 0;
}
