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

    cout << "Preorder Traversal: ";
    tree.displayPreorder();

    cout << "\nInorder Traversal: ";
    tree.displayInorder();

    cout << "\nPostorder Traversal: ";
    tree.displayPostorder();

    cout << endl;

    return 0;
}
