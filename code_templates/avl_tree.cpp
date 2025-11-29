#include <iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    int height;
    Node(int val)
    {
        right = left = nullptr;
        data = val;
        height = 0;
    }
};

class AVLTree
{

public:
    Node *root;

    AVLTree()
    {
        root = nullptr;
    }

    int height(Node *n)
    {
        return (n == NULL) ? 0 : n->height;
    }

    int getBalance(Node *n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    void updateHeight(Node *n)
    {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    Node *rightRotation(Node *root)
    {
        Node *newRoot = root->left; 
        Node *temp = newRoot->right; 

        newRoot->right = root; 
        root->left = temp;     

        updateHeight(newRoot);
        updateHeight(root);
        return newRoot; 
    }

    Node *leftRotation(Node *root)
    {
        Node *newRoot = root->right; 
        Node *temp = newRoot->left;  

        newRoot->left = root; 
        root->right = temp;   

        updateHeight(newRoot);
        updateHeight(root);
        return newRoot; 
    }

    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; 

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotation(node);

        if (balance < -1 && key > node->right->data)
            return leftRotation(node);

        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }

        return node;
    }

    void inorder(Node* node, vector<int>& elements) {
        if (!node) return;
        inorder(node->left, elements);
        elements.push_back(node->data);
        inorder(node->right, elements);
    }

    void printKthValues(int k) {
        vector<int> elements;
        inorder(root, elements);
        int n = elements.size();

        if (k <= 0 || k > n) {
            cout << "Invalid k value.\n";
            return;
        }

        int kthSmallest = elements[k - 1];
        int kthLargest = elements[n - k];

        cout << "K = " << k << endl;
        cout << "Kth Smallest = " << kthSmallest << endl;
        cout << "Kth Largest  = " << kthLargest << endl;
    }

    void printLeftRightHeights() {
        cout << "\nFrom Root Node (" << root->data << "):\n";
        cout << "Left Subtree Height  = " << height(root->left) << endl;
        cout << "Right Subtree Height = " << height(root->right) << endl;
    }

    void preOrder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main()
{
    AVLTree tree;

    int values[] = {10, 5, 15, 3, 7, 12};
    for (int val : values)
        tree.root = tree.insert(tree.root, val);

    cout << "Preorder Traversal of AVL Tree:\n";
    tree.preOrder(tree.root);
    cout << endl;

    int k;
    cout << "\nEnter k: ";
    cin >> k;

    tree.printKthValues(k);

    tree.printLeftRightHeights();

    return 0;
}
