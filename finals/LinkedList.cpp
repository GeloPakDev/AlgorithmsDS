#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};


void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " \n ";
        node = node->next;
    }
}

//Tasks
void multipleBy10(Node *node) {
    while (node != nullptr) {
        node->data = node->data * 10;
        node = node->next;
    }
}

void removeAllElements(Node *head) {
    Node *current = head;
    Node *next;
    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }
    head->next = nullptr;
}

void printNonZeroElements(Node *node) {
    int counter = 0;
    while (node != nullptr) {
        if (node->data != 0) {
            counter++;
        }
        node = node->next;
    }
    cout << counter;
}

void printZeroElements(Node *node) {
    int counter = 0;
    while (node != nullptr) {
        if (node->data == 0) {
            counter++;
        }
        node = node->next;
    }
    cout << counter;
}

void printEvenElements(Node *node) {
    int counter = 0;
    while (node != nullptr) {
        if (node->data % 2 == 0) {
            counter++;
        }
        node = node->next;
    }
    cout << counter;
}

bool isAscendingOrder(Node *head) {
    bool check = false;
    while (head->next != nullptr) {
        if (head->data <= head->next->data) {
            check = true;
        }
        head = head->next;
    }
    return check;
}

bool isDescendingOrder(Node *head) {
    bool check = false;
    while (head->next != nullptr) {
        if (head->data >= head->next->data) {
            check = true;
        }
        head = head->next;
    }
    return check;

}

Node *concatenateLinkedList(Node *listOne, Node *listTwo) {
    //Store two lists in the temp values
    Node *listOneTemp = listOne;
    //Get last node of the first List
    while (listOneTemp->next != nullptr) {
        listOneTemp = listOneTemp->next;
    }
    listOneTemp->next = listTwo;
    return listOne;
}

Node *removeFirstNode(Node *head) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void removeLastNode(Node *head) {
    while (head != nullptr) {
        if (head->next->next == nullptr) {
            head->next = nullptr;
            break;
        }
        head = head->next;
    }
}

int calculateAverage(Node *head) {
    int sum = 0;
    int totalElements = 0;
    while (head != nullptr) {
        sum += head->data;
        totalElements++;
        head = head->next;
    }
    return sum / totalElements;
}

Node *multipleValues(int value, Node *head) {
    Node *updatedList = head;
    while (head != nullptr) {
        head->data = head->data * value;
        head = head->next;
    }
    return updatedList;
}

void minMaxValues(Node *head) {
    int min = head->data;
    int max = head->data;
    while (head != nullptr) {
        if (head->data < min) {
            min = head->data;
        } else if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    cout << "Min value :" << min << "\n";
    cout << "Max value :" << max;
}

int numberOccurrences(int number, Node *head) {
    int count = 0;
    while (head != nullptr) {
        if (head->data == number) {
            count++;
        }
        head = head->next;
    }
    return count;
}
//TODO
Node *removeKthNode(Node *head, int k) {
    int counter = 0;
    Node *temp = head;
    while (temp != nullptr) {
        counter++;
        if (k == 1) {
            head = head->next;
            free(temp);
            return head;
        }
        if (counter == k - 1) {
            temp->next = temp->next->next;
            temp->next->next = nullptr;
        }
        if (temp->next->next == nullptr) {
            temp->next = nullptr;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void printKthNode(Node *head, int k) {
    int counter = 0;
    while (head != nullptr) {
        counter++;
        if (counter == k) {
            cout << head->data;
        }
        head = head->next;
    }
}

void printKthNextNode(Node *head, int k) {
    int counter = 0;
    while (head != nullptr) {
        counter++;
        if (counter == k) {
            cout << head->next->data;
        }
        head = head->next;
    }
}

void printKthBeforeNode(Node *head, int k) {
    int counter = 0;
    while (head != nullptr) {
        counter++;
        if (counter == k - 1) {
            cout << head->data;
        }
        head = head->next;
    }
}

//int main() {
//    Node *head;
//    Node *second;
//    Node *third;
//
//    // allocate 3 nodes in the heap
//    head = new Node();
//    second = new Node();
//    third = new Node();
//
//    head->data = 1; // assign data in first node
//    head->next = second; // Link first node with second
//
//    second->data = 2; // assign data to second node
//    second->next = third;
//
//    third->data = 3; // assign data to third node
//    third->next = nullptr;
//
//
//    Node *headOne;
//    Node *fourth;
//    Node *fifth;
//
//    // allocate 3 nodes in the heap
//    headOne = new Node();
//    fourth = new Node();
//    fifth = new Node();
//
//    headOne->data = 4; // assign data in first node
//    headOne->next = fourth; // Link first node with second
//
//    fourth->data = 5; // assign data to second node
//    fourth->next = fifth;
//
//    fifth->data = 6; // assign data to third node
//    fifth->next = nullptr;
//
//    return 0;
//}