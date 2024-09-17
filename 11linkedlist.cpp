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
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void addBeg(int item)
    {
        Node *newNode = new Node(item);
        newNode->next = head;
        head = newNode;
    }
    void addEnd(int item)
    {
        Node *newNode = new Node(item);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        if (head == NULL)
        {
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
    void delBeg()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void delEnd()
    {
        if (head == NULL)
        {
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
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    int noOfNode()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return 0;
        }
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool search(int item)
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return false;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int largestNum()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return INT_MIN;
        }
        Node *temp = head;
        int maxVal = INT_MIN;
        while (temp != NULL)
        {
            if (temp->data > maxVal)
            {
                maxVal = temp->data;
            }
            temp = temp->next;
        }
        return maxVal;
    }
    int smallestNum()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return INT_MAX;
        }
        Node *temp = head;
        int minVal = INT_MAX;
        while (temp != NULL)
        {
            if (temp->data < minVal)
            {
                minVal = temp->data;
            }
            temp = temp->next;
        }
        return minVal;
    }
    void reverse()
    {
        Node *prev = NULL, *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
    bool firstEqualMax()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return false;
        }
        int maxVal = largestNum();
        return head->data == maxVal;
    }
    bool checkIfSorted()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return false;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void addSorted(int item) {
    Node *curr = new Node(item);
    if (head == NULL) {
        head = curr;
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->next->data < item) {
        temp = temp->next;
    }
    if (temp == NULL) {
        curr->next = head;
        head = curr;
    }
    else {
        curr->next = temp->next;
        temp->next = curr;
    }
}
    void deleteAny(int item)
    {
        Node *temp = head, *prev;
        while (temp != NULL && temp->data != item)
        {
            prev = temp;
            temp = temp->next;
        }
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        else if (temp == head)
        {
            head = head->next;
            delete temp;
            return;
        }
        else if (temp == NULL)
        {
            cout << "Item not found" << endl;
            return;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
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
    cout << "6. Count Number of Nodes" << endl;
    cout << "7. Search an Element" << endl;
    cout << "8. Find Largest Number" << endl;
    cout << "9. Find Smallest Number" << endl;
    cout << "10. Reverse List" << endl;
    cout << "11. Check if First Element is Equal to Max" << endl;
    cout << "12. To add item at any place if it is sorted list" << endl;
    cout << "13. To delete item at any place" << endl;
    cout << "14. Exit" << endl;
    cout << "Enter your choice: ";
    while (choice!=14)
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
            cout << "Number of nodes: " << list.noOfNode() << endl;
            break;
        case 7:
            cout << "Enter the element to search: ";
            cin >> item;
            if (list.search(item))
                cout << "Element found" << endl;
            else
                cout << "Element not found" << endl;
            break;
        case 8:
            cout << "Largest number: " << list.largestNum() << endl;
            break;
        case 9:
            cout << "Smallest number: " << list.smallestNum() << endl;
            break;
        case 10:
            list.reverse();
            cout << "List reversed" << endl;
            break;
        case 11:
            if (list.firstEqualMax())
                cout << "First element is equal to the largest number" << endl;
            else
                cout << "First element is not equal to the largest number" << endl;
            break;
        case 12:
            cout << "Enter the element to add: ";
            cin >> item;
            if (list.checkIfSorted())
                list.addSorted(item);
            else
                cout << "Element can't be added" << endl;
            break;
        case 13:
            cout << "Enter the element to delete: ";
            cin >> item;
            list.deleteAny(item);
            break;
        case 14:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, try again!" << endl;
            break;
        }
    }
    return 0;
}