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

class Stack {
    Node* head;
    
public:
    Stack() {
        head = NULL;  
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int item) {
        Node* newNode = new Node(item);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    int peek() {
        if (head == NULL) {
            return INT_MIN;  
        }
        return head->a;
    }

    int pop() {
        if (head == NULL) {
            return INT_MIN;  
        }
        Node* temp = head;
        head = head->next;
        int poppedValue = temp->a;
        delete temp;  
        return poppedValue;
    }

    void display() {
        if (head == NULL) {
            cout << "Stack is empty." << endl;
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
    Stack s1;
    int i = 0;
    cout << "To push an integer type 1\n"
         << "To pop an integer type 2\n"
         << "To peek an integer type 3\n"
         << "To display stack type 4\n"
         << "To stop the stack type 5\n";

    while (i != 5) {
        cin >> i;
        switch (i) {
        case 1: {
            int a;
            cout << "Enter a value to push: ";
            cin >> a;
            s1.push(a);
            cout << "Pushed " << a << "\n";
            break;
        }
        case 2: {
            int poppedValue = s1.pop();
            if (poppedValue == INT_MIN) {
                cout << "Stack is empty, nothing to pop!\n";
            } else {
                cout << "Popped value: " << poppedValue << "\n";
            }
            break;
        }
        case 3: {
            int topValue = s1.peek();
            if (topValue == INT_MIN) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Top value: " << topValue << "\n";
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
        }
    }

    return 0;
}