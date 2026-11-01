#include <iostream>
using namespace std;

class Heap {
    int arr[100];
    int size;
    bool isMin;

public:
    Heap(bool minHeap) {
        size = 0;
        isMin = minHeap;
    }

    bool compare(int a, int b) {
        if (isMin)
            return a < b;
        else
            return a > b;
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (compare(arr[i], arr[parent])) {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int best = i;

            if (left < size && compare(arr[left], arr[best]))
                best = left;

            if (right < size && compare(arr[right], arr[best]))
                best = right;

            if (best != i) {
                swap(arr[i], arr[best]);
                i = best;
            }
            else
                break;
        }
    }

    void create() {
        int n, value;

        cout << "How many values? ";
        cin >> n;

        size = 0;

        for (int i = 0; i < n && i < 100; i++) {
            cout << "Enter value: ";
            cin >> value;

            arr[size] = value;
            heapifyUp(size);
            size++;
        }
    }

    void read() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Heap: ";

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void update(int oldValue, int newValue) {
        int i = 0;

        while (i < size && arr[i] != oldValue)
            i++;

        if (i == size) {
            cout << "Value not found\n";
            return;
        }

        arr[i] = newValue;

        if (i > 0 && compare(arr[i], arr[(i - 1) / 2]))
            heapifyUp(i);
        else
            heapifyDown(i);

        cout << "Value updated\n";
    }

    void deleteValue(int value) {
        int i = 0;

        while (i < size && arr[i] != value)
            i++;

        if (i == size) {
            cout << "Value not found\n";
            return;
        }

        arr[i] = arr[size - 1];
        size--;

        if (i < size) {
            if (i > 0 && compare(arr[i], arr[(i - 1) / 2]))
                heapifyUp(i);
            else
                heapifyDown(i);
        }

        cout << "Value deleted\n";
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Deleted root: " << arr[0] << endl;

        arr[0] = arr[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    void preorder(int i) {
        if (i >= size)
            return;

        cout << arr[i] << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }

    void inorder(int i) {
        if (i >= size)
            return;

        inorder(2 * i + 1);
        cout << arr[i] << " ";
        inorder(2 * i + 2);
    }

    void postorder(int i) {
        if (i >= size)
            return;

        postorder(2 * i + 1);
        postorder(2 * i + 2);
        cout << arr[i] << " ";
    }

    void levelOrder() {
        read();
    }

    void traversals() {
        cout << "Preorder: ";
        preorder(0);

        cout << "\nInorder: ";
        inorder(0);

        cout << "\nPostorder: ";
        postorder(0);

        cout << "\nLevel Order: ";
        levelOrder();

        cout << endl;
    }
};

int main() {
    int type, choice;
    int oldValue, newValue, value;

    cout << "1. Min Heap\n";
    cout << "2. Max Heap\n";
    cout << "Choose heap type: ";
    cin >> type;

    Heap h(type == 1);

    do {
        cout << "\n1. Create\n";
        cout << "2. Read\n";
        cout << "3. Update\n";
        cout << "4. Delete a value\n";
        cout << "5. Delete root\n";
        cout << "6. Traversals\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.create();
                break;

            case 2:
                h.read();
                break;

            case 3:
                cout << "Enter old value: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                h.update(oldValue, newValue);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                h.deleteValue(value);
                break;

            case 5:
                h.deleteRoot();
                break;

            case 6:
                h.traversals();
                break;

            case 0:
                cout << "Program ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}