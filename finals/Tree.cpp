#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

Node *newTreeNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void printPostorder(Node *node) {
    if (node == nullptr)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

int SumOfNodes(Node *root) {
    if (root == nullptr)
        return 0;
    return (root->data + SumOfNodes(root->left) + SumOfNodes(root->right));
}

int totalNodes(Node *root) {
    if (root == nullptr)
        return 0;

    int l = totalNodes(root->left);
    int r = totalNodes(root->right);

    return 1 + l + r;
}




int main() {
    struct Node *root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);

    // Function call
    //printPostorder(root);
    int a = totalNodes(root);
    cout << a;

    return 0;
}