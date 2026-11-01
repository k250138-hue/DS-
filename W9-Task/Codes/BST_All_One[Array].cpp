
#include <iostream>
using namespace std;

const int MAX = 100;

class BST {
private:
    int data[MAX];
    int leftChild[MAX];
    int rightChild[MAX];

    int root;
    int count;

    // Create a new node
    int createNode(int value) {
        data[count] = value;
        leftChild[count] = -1;
        rightChild[count] = -1;

        return count++;
    }

    // Insert a value into the BST
    int insertNode(int node, int value) {
        if (node == -1) {
            return createNode(value);
        }

        if (value < data[node]) {
            leftChild[node] =
                insertNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] =
                insertNode(rightChild[node], value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(int node, int value) {
        if (node == -1) {
            return false;
        }

        if (data[node] == value) {
            return true;
        }

        if (value < data[node]) {
            return searchNode(leftChild[node], value);
        }

        return searchNode(rightChild[node], value);
    }

    // In-order traversal for sorted output
    void inorder(int node) {
        if (node == -1) {
            return;
        }

        inorder(leftChild[node]);
        cout << data[node] << " ";
        inorder(rightChild[node]);
    }

    // Find the smallest node in a subtree
    int findMin(int node) {
        while (leftChild[node] != -1) {
            node = leftChild[node];
        }

        return node;
    }

    // Delete a value from the BST
    int deleteNode(int node, int value) {
        if (node == -1) {
            return -1;
        }

        if (value < data[node]) {
            leftChild[node] =
                deleteNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] =
                deleteNode(rightChild[node], value);
        }
        else {
            // Case 1: No children
            if (leftChild[node] == -1 &&
                rightChild[node] == -1) {
                return -1;
            }

            // Case 2: Only right child
            if (leftChild[node] == -1) {
                return rightChild[node];
            }

            // Case 2: Only left child
            if (rightChild[node] == -1) {
                return leftChild[node];
            }

            // Case 3: Two children
            // Find the in-order successor
            int successor = findMin(rightChild[node]);

            data[node] = data[successor];

            rightChild[node] =
                deleteNode(rightChild[node],
                           data[successor]);
        }

        return node;
    }

public:
    BST() {
        root = -1;
        count = 0;
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

const int MAX = 100;

class BST {
private:
    int data[MAX];
    int leftChild[MAX];
    int rightChild[MAX];

    int root;
    int count;

    // Create a new node
    int createNode(int value) {
        if (count >= MAX) {
            cout << "BST is full!" << endl;
            return -1;
        }

        data[count] = value;
        leftChild[count] = -1;
        rightChild[count] = -1;

        return count++;
    }

    // Insert a value into the BST
    int insertNode(int node, int value) {
        if (node == -1) {
            return createNode(value);
        }

        if (value < data[node]) {
            leftChild[node] =
                insertNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] =
                insertNode(rightChild[node], value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(int node, int value) {
        if (node == -1) {
            return false;
        }

        if (data[node] == value) {
            return true;
        }

        if (value < data[node]) {
            return searchNode(leftChild[node], value);
        }

        return searchNode(rightChild[node], value);
    }

    // In-order traversal for sorted output
    void inorder(int node) {
        if (node == -1) {
            return;
        }

        inorder(leftChild[node]);
        cout << data[node] << " ";
        inorder(rightChild[node]);
    }

    // Pre-order traversal
    void preorder(int node) {
        if (node == -1) {
            return;
        }

        cout << data[node] << " ";
        preorder(leftChild[node]);
        preorder(rightChild[node]);
    }

    // Post-order traversal
    void postorder(int node) {
        if (node == -1) {
            return;
        }

        postorder(leftChild[node]);
        postorder(rightChild[node]);
        cout << data[node] << " ";
    }

    // Level-order traversal
    void levelOrder() {
        if (root == -1) {
            return;
        }

        int queue[MAX];
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            int node = queue[front++];

            cout << data[node] << " ";

            if (leftChild[node] != -1) {
                queue[rear++] = leftChild[node];
            }

            if (rightChild[node] != -1) {
                queue[rear++] = rightChild[node];
            }
        }
    }

    // Find the smallest node in a subtree
    int findMin(int node) {
        while (leftChild[node] != -1) {
            node = leftChild[node];
        }

        return node;
    }

    // Find the largest node in a subtree
    int findMax(int node) {
        while (rightChild[node] != -1) {
            node = rightChild[node];
        }

        return node;
    }

    // Delete a value from the BST
    int deleteNode(int node, int value) {
        if (node == -1) {
            return -1;
        }

        if (value < data[node]) {
            leftChild[node] =
                deleteNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] =
                deleteNode(rightChild[node], value);
        }
        else {
            // Case 1: No children
            if (leftChild[node] == -1 &&
                rightChild[node] == -1) {
                return -1;
            }

            // Case 2: Only right child
            if (leftChild[node] == -1) {
                return rightChild[node];
            }

            // Case 2: Only left child
            if (rightChild[node] == -1) {
                return leftChild[node];
            }

            // Case 3: Two children
            // Find the in-order successor
            int successor = findMin(rightChild[node]);

            data[node] = data[successor];

            rightChild[node] =
                deleteNode(rightChild[node],
                           data[successor]);
        }

        return node;
    }

public:
    BST() {
        root = -1;
        count = 0;
    }

    void create() {
        int n, value;

        cout << "How many values? ";
        cin >> n;

        if (n < 0 || n > MAX - count) {
            cout << "Invalid number of values." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        }
    }

    void insert(int value) {
        if (count >= MAX) {
            cout << "BST is full!" << endl;
            return;
        }

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
        if (root == -1) {
            cout << "BST is empty." << endl;
            return;
        }

        cout << "Minimum node: "
             << data[findMin(root)] << endl;
    }

    void maxNode() {
        if (root == -1) {
            cout << "BST is empty." << endl;
            return;
        }

        cout << "Maximum node: "
             << data[findMax(root)] << endl;
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
