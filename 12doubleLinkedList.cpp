#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int item)
    {
        data = item;
        next = NULL;
        prev = NULL;
    }
};

class doubleyLinkedList
{
    Node *head;

public:
    doubleyLinkedList()
    {
        head = NULL; // Corrected head initialization
    }

    void addBeg(int item)
    {
        Node *newNode = new Node(item);
        if (head == NULL)
        { // Corrected comparison
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void addEnd(int item)
    {
        Node *newNode = new Node(item);
        if (head == NULL)
        { // Corrected comparison
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display()
    {
        if (head == NULL)
        { // Corrected comparison
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse()
    {
        if (head == NULL)
        { // Corrected comparison
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void delEnd()
    {
        if (head == NULL)
        { // Corrected comparison
            cout << "Empty list" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void delBeg()
    {
        if (head == NULL)
        { // Corrected comparison
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void atAnyPosition(int item, int newVal)
    {
        Node *x = head;
        while (x != NULL && x->data != item)
        {
            x = x->next;
        }
        if (x == NULL)
        {
            cout << "Item not found in the list." << endl;
            return; // Item not found
        }
        Node *newNode = new Node(newVal);
        if (x->prev == NULL)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            x->prev->next = newNode;
            newNode->prev = x->prev;
            newNode->next = x;
            x->prev = newNode;
        }
    }
    void delAnyPos(int item)
    {
        Node *x = head;
        while (x != NULL && x->data != item)
        {
            x = x->next;
        }
        if (x == NULL)
        {
            cout << "Item not found in the list." << endl;
            return;
        }
        if (x->prev == NULL)
        {
            delBeg();
            return;
        }
        else if (x->next == NULL)
        {
            delEnd();
            return;
        }
        x->prev->next = x->next;
        x->next->prev = x->prev;
        delete x;
    }
};

int main()
{
    doubleyLinkedList list;
    int choice = 0, item;
    cout << "\n--- Menu ---" << endl;
    cout << "1. Add at Beginning" << endl;
    cout << "2. Add at End" << endl;
    cout << "3. Display List" << endl;
    cout << "4. Delete from Beginning" << endl;
    cout << "5. Delete from End" << endl;
    cout << "6. Reverse List" << endl;
    cout << "7. Add at any position" << endl;
    cout << "8. Delete any position" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";

    while (choice != 9)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to add at beginning: ";
            cin >> item;
            list.addBeg(item);
            break;
        case 2:
            cout << "Enter the element to add at end: ";
            cin >> item;
            list.addEnd(item);
            break;
        case 3:
            list.display();
            break;
        case 4:
            list.delBeg();
            break;
        case 5:
            list.delEnd();
            break;
        case 6:
            list.displayReverse();
            break;
        case 7:
            int a;
            cout << "Please give the number at which position you want to insert: ";
            cin >> a;
            cout << "Give the item you want to insert: ";
            int b;
            cin >> b;
            list.atAnyPosition(a, b);
            break;
        case 8:
            int c;
            cout << "enter the node your want to delete: ";
            cin >> c;
            list.delAnyPos(c);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}