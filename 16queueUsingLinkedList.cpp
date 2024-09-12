#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int a;
    Node* next;

    Node(int item) {
        a = item;
        next = NULL;  
    }
};

class Queue {
    Node* head;

public:
    Queue() {
        head = NULL;  
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        Node* temp = head;
        head = head->next;
        int dequeuedValue = temp->a;
        delete temp;  
        return dequeuedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return head->a;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->a << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue s1;
    int i = 0;

    cout << "To enqueue an integer type 1\n"
         << "To dequeue an integer type 2\n"
         << "To peek an integer type 3\n"
         << "To display queue type 4\n"
         << "To stop the queue type 5\n";

    while (i != 5) {
        cin >> i;
        switch (i) {
        case 1: {
            int a;
            cout << "Enter a value to enqueue: ";
            cin >> a;
            s1.enqueue(a);
            cout << "Enqueued " << a << "\n";
            break;
        }
        case 2: {
            int dequeuedValue = s1.dequeue();
            if (dequeuedValue == INT_MIN) {
                cout << "Queue is empty, nothing to dequeue!\n";
            } else {
                cout << "Dequeued value: " << dequeuedValue << "\n";
            }
            break;
        }
        case 3: {
            int frontValue = s1.peek();
            if (frontValue != INT_MIN) {
                cout << "Front value: " << frontValue << "\n";
            }
            break;
        }
        case 4: {
            s1.display();
            break;
        }
        case 5: {
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Input not found, try again.\n";
            break;
        }
    }

    return 0;
}