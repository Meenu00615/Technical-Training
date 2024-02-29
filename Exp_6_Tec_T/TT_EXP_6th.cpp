#include <iostream>
#include <queue>

using namespace std;

//binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//preorder function to perform preorder traversal of a binary tree
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//function to create a binary tree based on user input
Node* createBinaryTree() {
    int val;
    cout << "Enter the value of the root node: ";
    cin >> val;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter the value for the left child of " << current->data << " (-1 for null): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter the value for the right child of " << current->data << " (-1 for null): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }

        if (current->data == 3) // 
            break;
    }

    return root;
}

int main() {
    //binary tree based on user input
    Node* root = createBinaryTree();

    //preorder traversal and print the nodes
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    return 0;
}
