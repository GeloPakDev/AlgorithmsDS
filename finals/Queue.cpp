#include <iostream>

using namespace std;
#define SIZE 1000

class Queue {
    int *array;
    int capacity;
    int front;
    int rear;
    int count;
public:
    Queue(int size = SIZE);

    ~Queue();

    int dequeue();

    void enqueue(int x);

    int peek();

    int size();

    bool isEmpty();

    bool isFull();

};

Queue::Queue(int size) {
    array = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] array;
}

int Queue::dequeue() {
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    int x = array[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % capacity;
    array[rear] = item;
    count++;
}

int Queue::peek() {
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return array[front];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}

int countElements(Queue queue) {
    int counter = 0;
    while (!queue.isEmpty()) {
        counter++;
        queue.dequeue();
    }
    return counter;
}

void removeAllElements(Queue queue) {
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
}


//int main() {
//    Queue queue(5);
//
//    queue.enqueue(1);
//    queue.enqueue(2);
//    queue.enqueue(3);
//}