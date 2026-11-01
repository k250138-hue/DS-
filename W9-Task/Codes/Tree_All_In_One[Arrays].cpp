
#include <iostream>
using namespace std;

class BinaryTree {
    static const int SIZE = 100;
    static const int EMPTY = -1;

    int tree[SIZE];

    void preorder(int index) {
        if (index >= SIZE || tree[index] == EMPTY)
            return;

        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void inorder(int index) {
        if (index >= SIZE || tree[index] == EMPTY)
            return;

        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }

    void postorder(int index) {
        if (index >= SIZE || tree[index] == EMPTY)
            return;

        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }

public:
    BinaryTree() {
        initialize();
    }

    void initialize() {
        for (int i = 0; i < SIZE; i++)
            tree[i] = EMPTY;
    }

    void create() {
        initialize();

        int n, value;

        cout << "How many nodes? ";
        cin >> n;

        if (n < 0 || n > SIZE) {
            cout << "Invalid number of nodes\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
        }
    }

    void insertNode(int value) {
        if (value == EMPTY) {
            cout << "-1 is reserved for an empty position\n";
            return;
        }

        for (int i = 0; i < SIZE; i++) {
            if (tree[i] == EMPTY) {
                tree[i] = value;
                cout << "Node inserted\n";
                return;
            }
        }

        cout << "Tree is full\n";
    }

    void read() {
        bool found = false;

        cout << "Tree Array:\n";

        for (int i = 0; i < SIZE; i++) {
            if (tree[i] != EMPTY) {
                cout << "Index " << i << ": "
                     << tree[i] << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Tree is empty\n";
    }

    void searchNode(int value) {
        for (int i = 0; i < SIZE; i++) {
            if (tree[i] == value) {
                cout << value << " found at index "
                     << i << endl;
                return;
            }
        }

        cout << value << " not found\n";
    }

    void updateNode(int oldValue, int newValue) {
        if (newValue == EMPTY) {
            cout << "-1 is reserved for an empty position\n";
            return;
        }

        for (int i = 0; i < SIZE; i++) {
            if (tree[i] == oldValue) {
                tree[i] = newValue;
                cout << "Node updated\n";
                return;
            }
        }

        cout << "Value not found\n";
    }

    void deleteNode(int value) {
        int index = -1;
        int last = -1;

        for (int i = 0; i < SIZE; i++) {
            if (tree[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Value not found\n";
            return;
        }

        for (int i = SIZE - 1; i >= 0; i--) {
            if (tree[i] != EMPTY) {
                last = i;
                break;
            }
        }

        tree[index] = tree[last];
        tree[last] = EMPTY;

        cout << "Node deleted\n";
    }

    void Preorder() {
        if (tree[0] == EMPTY) {
            cout << "Tree is empty\n";
            return;
        }

        preorder(0);
        cout << endl;
    }

    void Inorder() {
        if (tree[0] == EMPTY) {
            cout << "Tree is empty\n";
            return;
        }

        inorder(0);
        cout << endl;
    }

    void Postorder() {
        if (tree[0] == EMPTY) {
            cout << "Tree is empty\n";
            return;
        }

        postorder(0);
        cout << endl;
    }

    void LevelOrder() {
        bool found = false;

        for (int i = 0; i < SIZE; i++) {
            if (tree[i] != EMPTY) {
                cout << tree[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "Tree is empty";

        cout << endl;
    }

    void traversals() {
        cout << "Preorder: ";
        Preorder();

        cout << "Inorder: ";
        Inorder();

        cout << "Postorder: ";
        Postorder();

        cout << "Level Order: ";
        LevelOrder();
    }
};

int main() {
    BinaryTree t;

    t.insertNode(10);
    t.insertNode(25);
    t.insertNode(5);
    t.insertNode(3);
    t.insertNode(12);
    t.insertNode(24);
    t.insertNode(30);

    cout << "\nReading Tree:\n";
    t.read();

    cout << "\nSearching for 12:\n";
    t.searchNode(12);

    cout << "\nUpdating 12 to 15:\n";
    t.updateNode(12, 15);

    cout << "\nDeleting 25:\n";
    t.deleteNode(25);

    cout << "\nFinal Tree:\n";
    t.read();

    cout << "\nTree Traversals:\n";
    t.traversals();

    return 0;
}
