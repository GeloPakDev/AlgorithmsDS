#include <iostream>

using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]{}; // Maximum size of Stack

    Stack() { top = -1; }

    bool push(int x);

    int pop();

    int peek();

    bool isEmpty() const;
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        return false;
    } else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() const {
    return (top < 0);
}

int averageValue(Stack stack) {
    int sum = 0;
    int counter = 0;
    while (!stack.isEmpty()) {
        counter++;
        sum += stack.peek();
        stack.pop();
    }
    return sum / counter;
}

int maxValue(Stack stack) {
    int max = stack.peek();
    while (!stack.isEmpty()) {
        if (stack.peek() > max) {
            max = stack.peek();
        }
        stack.pop();
    }
    return max;
}

int minValue(Stack stack) {
    int min = stack.peek();
    while (!stack.isEmpty()) {
        if (stack.peek() < min) {
            min = stack.peek();
        }
        stack.pop();
    }
    return min;
}

int main() {
    class Stack stack;
    stack.push(10);
    stack.push(-20);
    stack.push(-8920);
    stack.push(2120);
    stack.push(30);

    int i = minValue(stack);
    cout << i;
}