#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
private:
    Node* root;

    void deleteTree(Node* temp)
    {
        if (temp == NULL)
            return;

        deleteTree(temp->left);
        deleteTree(temp->right);
        delete temp;
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insertNode(int value)
    {
        Node* newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                queue[rear++] = temp->left;
            }

            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                queue[rear++] = temp->right;
            }
        }
    }

    void create()
    {
        deleteTree(root);
        root = NULL;

        int n, value;

        cout << "How many nodes? ";
        cin >> n;

        if (n < 0 || n > 100)
        {
            cout << "Invalid number of nodes\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
        }
    }

    void read()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            cout << temp->data << " ";

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }
    }

    void searchNode(int value)
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->data == value)
            {
                cout << value << " found\n";
                return;
            }

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        cout << value << " not found\n";
    }

    void updateNode(int oldValue, int newValue)
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->data == oldValue)
            {
                temp->data = newValue;
                cout << "Node updated\n";
                return;
            }

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        cout << "Value not found\n";
    }

    void deleteNode(int value)
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        Node* target = NULL;
        Node* deepest = NULL;
        Node* deepestParent = NULL;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->data == value && target == NULL)
                target = temp;

            if (temp->left != NULL)
            {
                deepestParent = temp;
                deepest = temp->left;
                queue[rear++] = temp->left;
            }

            if (temp->right != NULL)
            {
                deepestParent = temp;
                deepest = temp->right;
                queue[rear++] = temp->right;
            }
        }

        if (target == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        if (deepest == NULL)
        {
            delete root;
            root = NULL;
            cout << "Node deleted\n";
            return;
        }

        target->data = deepest->data;

        if (deepestParent->left == deepest)
            deepestParent->left = NULL;
        else
            deepestParent->right = NULL;

        delete deepest;

        cout << "Node deleted\n";
    }

    void minNode()
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        int minimum = root->data;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->data < minimum)
                minimum = temp->data;

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        cout << "Minimum node: " << minimum << endl;
    }

    void maxNode()
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        int maximum = root->data;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* temp = queue[front++];

            if (temp->data > maximum)
                maximum = temp->data;

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        cout << "Maximum node: " << maximum << endl;
    }

    void preorder(Node* temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void inorder(Node* temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void postorder(Node* temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void displayPreorder()
    {
        preorder(root);
    }

    void displayInorder()
    {
        inorder(root);
    }

    void displayPostorder()
    {
        postorder(root);
    }

    void displayLevelOrder()
    {
        read();
    }

    ~BinaryTree()
    {
        deleteTree(root);
    }
};

int main()
{
    BinaryTree tree;

    tree.insertNode(10);
    tree.insertNode(25);
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(24);
    tree.insertNode(30);

    cout << "Level Order Traversal: ";
    tree.displayLevelOrder();

    cout << "\nPreorder Traversal: ";
    tree.displayPreorder();

    cout << "\nInorder Traversal: ";
    tree.displayInorder();

    cout << "\nPostorder Traversal: ";
    tree.displayPostorder();

    cout << "\n\nSearching for 12: ";
    tree.searchNode(12);

    cout << "\nUpdating 12 to 15:\n";
    tree.updateNode(12, 15);

    cout << "\nMinimum Node:\n";
    tree.minNode();

    cout << "Maximum Node:\n";
    tree.maxNode();

    cout << "\nDeleting 25:\n";
    tree.deleteNode(25);

    cout << "\nTree after deletion: ";
    tree.read();

    cout << endl;

    return 0;
}
