#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int item)
    {
        data = item;
        next = NULL;
    }
};
class LinkedList
{
private:
    Node *last;

public:
    LinkedList()
    {
        last = NULL;
    }
    void addBeg(int item)
    {
        Node *newNode = new Node(item);
        if(last==NULL){
            newNode->next = newNode;
            last = newNode;
            return;
        }
        newNode->next=last->next;
        last->next=newNode;
        return;
    }
    void addEnd(int item)
    {
        Node *newNode = new Node(item);
        if(last==NULL){
            newNode->next = newNode;
            last = newNode;
            return;
        }
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
        return;
    }
    void display()
    {
        if (last == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = last->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != last->next);
        cout<<endl;
    }
    void delBeg()
    {
        if (last == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        if(last->next==last){
            delete last;
            last=NULL;
            return;
        }
        Node *temp = last->next;
        last->next = temp->next;
        delete temp;
        return;
    }
    void delEnd()
    {
        if (last == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        if (last->next == last)
        {
            delete last;
            last = NULL;
            return;
        }
        Node *temp = last->next;
        Node *prev = last;
        while (temp->next != last->next)  
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = last->next;  
        delete last;
        last = prev;  
    }
};
int main()
{
    LinkedList list;
    int choice, item;
    cout << "\n--- Menu ---" << endl;
    cout << "1. Add at Beginning" << endl;
    cout << "2. Add at End" << endl;
    cout << "3. Display List" << endl;
    cout << "4. Delete from Beginning" << endl;
    cout << "5. Delete from End" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    while (choice!=6)
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
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, try again!" << endl;
            break;
        }
    }
    return 0;
}