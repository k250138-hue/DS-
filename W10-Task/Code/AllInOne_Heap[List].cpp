#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Heap {
    Node* head;
    int size;
    bool isMin;

    Node* getNode(int index) {
        Node* temp = head;

        for (int i = 0; i < index && temp != NULL; i++)
            temp = temp->next;

        return temp;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void removeLast() {
        if (head == NULL)
            return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
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

            Node* childNode = getNode(i);
            Node* parentNode = getNode(parent);

            if (compare(childNode->data, parentNode->data)) {
                swap(childNode->data, parentNode->data);
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

            Node* current = getNode(i);
            Node* leftNode = getNode(left);
            Node* rightNode = getNode(right);

            if (left < size &&
                compare(leftNode->data, getNode(best)->data))
                best = left;

            if (right < size &&
                compare(rightNode->data, getNode(best)->data))
                best = right;

            if (best != i) {
                Node* bestNode = getNode(best);

                swap(current->data, bestNode->data);
                i = best;
            }
            else
                break;
        }
    }

    void preorder(int i) {
        if (i >= size)
            return;

        cout << getNode(i)->data << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }

    void inorder(int i) {
        if (i >= size)
            return;

        inorder(2 * i + 1);
        cout << getNode(i)->data << " ";
        inorder(2 * i + 2);
    }

    void postorder(int i) {
        if (i >= size)
            return;

        postorder(2 * i + 1);
        postorder(2 * i + 2);
        cout << getNode(i)->data << " ";
    }

public:
    Heap(bool minHeap) {
        head = NULL;
        size = 0;
        isMin = minHeap;
    }

    ~Heap() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void create() {
        int n, value;

        while (head != NULL)
            removeLast();

        size = 0;

        cout << "How many values? ";
        cin >> n;

        if (n < 0) {
            cout << "Invalid size\n";
            return;
        }

        if (n > 100) {
            cout << "Maximum 100 values allowed\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;

            insertEnd(value);
            heapifyUp(size);
            size++;
        }
    }

    void read() {
        if (head == NULL) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Heap: ";

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void update(int oldValue, int newValue) {
        int i = 0;
        Node* temp = head;

        while (temp != NULL && temp->data != oldValue) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        temp->data = newValue;

        if (i > 0 &&
            compare(temp->data, getNode((i - 1) / 2)->data))
            heapifyUp(i);
        else
            heapifyDown(i);

        cout << "Value updated\n";
    }

    void deleteValue(int value) {
        int i = 0;
        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        temp->data = getNode(size - 1)->data;
        removeLast();
        size--;

        if (i < size) {
            if (i > 0 &&
                compare(getNode(i)->data,
                        getNode((i - 1) / 2)->data))
                heapifyUp(i);
            else
                heapifyDown(i);
        }

        cout << "Value deleted\n";
    }

    void deleteRoot() {
        if (head == NULL) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Deleted root: " << head->data << endl;

        head->data = getNode(size - 1)->data;
        removeLast();
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    void traversals() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Preorder: ";
        preorder(0);

        cout << "\nInorder: ";
        inorder(0);

        cout << "\nPostorder: ";
        postorder(0);

        cout << "\nLevel Order: ";
        read();

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

    if (type != 1 && type != 2) {
        cout << "Invalid heap type\n";
        return 0;
    }

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