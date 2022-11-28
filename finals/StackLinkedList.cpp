#include <iostream>

using namespace std;

class StackNode {
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data) {
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

int isEmpty(StackNode *root) {
    return !root;
}

void push(StackNode **root, int data) {
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(StackNode **root) {
    if (isEmpty(*root))
        return -1;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode *root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

//Tasks
void removeAllElements(StackNode *stackNode) {
    while (!isEmpty(stackNode)) {
        cout << pop(&stackNode) << endl;
    }
}

void printAllValues(StackNode *stackNode) {
    while (!isEmpty(stackNode)) {
        cout << pop(&stackNode) << endl;
    }
}

int countElements(StackNode *stackNode) {
    int counter = 0;
    while (!isEmpty(stackNode)) {
        pop(&stackNode);
        counter++;
    }
    return counter;
}

int averageValue(StackNode *stackNode) {
    int counter = 0;
    int sum = 0;
    while (!isEmpty(stackNode)) {
        sum += stackNode->data;
        counter++;
        pop(&stackNode);
    }
    return sum / counter;
}

int minValue(StackNode *stackNode) {
    int min = stackNode->data;
    while (!isEmpty(stackNode)) {
        if (stackNode->data < min) {
            min = stackNode->data;
        }
        pop(&stackNode);
    }
    return min;
}

int maxValue(StackNode *stackNode) {
    int max = stackNode->data;
    while (!isEmpty(stackNode)) {
        if (stackNode->data > max) {
            max = stackNode->data;
        }
        pop(&stackNode);
    }
    return max;
}


//int main() {
//    StackNode *root = nullptr;
//    push(&root, 1);
//    push(&root, 2);
//    push(&root, 3);
//    push(&root, -92);
//    push(&root, 32);
//    push(&root, 12);
//}