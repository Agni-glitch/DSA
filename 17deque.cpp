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
class deque
{
    Node *front;
    Node *rear;
public:
    deque()
    {
        front = NULL;
        rear = NULL;
    }
    void addFront(int item){
        Node* newNode = new Node(item);
        if(front==NULL){
            front=newNode;
            rear=newNode;
            return;
        }
        newNode->next=front;
        front->prev=newNode;
        front=newNode;
        return;
    }
    void addRear(int item){
        Node* newNode = new Node(item);
        if(front==NULL){
            front=newNode;
            rear=newNode;
            return;
        }
        Node* temp=front;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        rear=newNode;
        return;
    }
    int delFront(){
        if(front==NULL||rear==NULL){
            cout<<"Empty list";
            return INT16_MIN;
        }
        Node *temp=front;
        front=front->next;
        int a = temp->data;
        front->prev=NULL;
        delete temp;
        return a;
    }
    int delRear(){
        if(front==NULL||rear==NULL){
            cout<<"Empty list";
            return INT16_MIN;
        }
        Node *temp=front;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        int a= temp->data;
        temp->prev->next=NULL;
        rear=temp->prev;
        delete temp;
        return a;
    }
    void display(){
        if(front==NULL||rear==NULL){
            cout<<"Empty list";
            return;
        }
        Node * temp= front;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    deque s1;
    int i = 0;
    cout << "To add front integer type 1\n"
         << "To add rear integer type 2\n"
         << "To display type 3\n"
         << "To delete front type 4\n"
         << "To delete rear type 5\n"
         << "To stop the queue type 6\n";

    while (i != 6) {
        cin >> i;
        switch (i) {
        case 1: {
            int a;
            cout << "Enter a value to add at front: ";
            cin >>a;
            s1.addFront(a);
            cout << "Front: " << a << "\n";
            break;
        }
        case 2: {
            int b;
            cout << "Enter a value to add at rear: ";
            cin >>b;
            s1.addRear(b);
            cout << "rear: " << b << "\n";
            break;
        }
        case 3: {
            s1.display();
            break;
        }
        case 4: {
            int delBeg = s1.delFront();
            if (delBeg == INT16_MIN) {
                cout << "Deque is empty\n";
            } else {
                cout << "Deleted front: " << delBeg << "\n";
            }
            break;
        }
        case 5:{
            int delEnd = s1.delRear();
            if (delEnd == INT16_MIN) {
                cout << "Deque is empty\n";
            } else {
                cout << "Deleted rear: " << delEnd << "\n";
            }
            break;
        }
        case 6: {
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