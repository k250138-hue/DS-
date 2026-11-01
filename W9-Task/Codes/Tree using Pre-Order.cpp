#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Build binary tree from preorder array
Node* buildTree(int preorder[], int& index, int size) {

    // If array ends
    if (index >= size)
        return NULL;

    // If current value represents an empty node
    if (preorder[index] == -1) {
        index++;
        return NULL;
    }

    // Create a new node
    Node* root = new Node();

    root->data = preorder[index];
    root->left = NULL;
    root->right = NULL;

    index++;

    // Construct left subtree
    root->left = buildTree(preorder, index, size);

    // Construct right subtree
    root->right = buildTree(preorder, index, size);

    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main() {

    int preorder[] = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };

    int size = sizeof(preorder) / sizeof(preorder[0]);
    int index = 0;

    // Construct the binary tree
    Node* root = buildTree(preorder, index, size);

    // Display inorder traversal
    cout << "Inorder traversal of constructed tree: ";

    inorder(root);

    cout << endl;

    return 0;
}

