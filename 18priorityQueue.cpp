#include <iostream>
#include <climits>
using namespace std;
class Node{
    public:
    int data;
    int priority;
    Node* next;
    Node(int a,int b){
        data=a;
        priority=b;
        next=NULL;
    }
};
class priorityQueue{
    Node* front;
    public:
    priorityQueue(){
        front=NULL;
    }
    void enQueue(int item, int p){
        Node* newNode= new Node(item,p);
        if(front==NULL||front->priority>p){
            newNode->next=front;
            front=newNode;
            return;
        }
        Node* temp= front;
        while(temp->next->priority<=p&&temp->next!=NULL){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }
    int deQueue(){
        if(front==NULL){
            cout<<"Empty List";
            return INT16_MIN;
        }
        Node * temp= front;
        front=front->next;
        int a= temp->data;
        delete temp;
        return a;
    }
    void display(){
        if(front==NULL){
            cout<<"Empty List";
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
    priorityQueue s1;
    int i = 0;
    cout << "To enqueue an integer type 1\n"
         << "To dequeue an integer type 2\n"
         << "To display queue type 3\n"
         << "To stop the queue type 4\n";

    while (i != 4) {
        cin >> i;
        switch (i) {
        case 1: {
            int a,b;
            cout << "Enter a value to enqueue and priority respectively: ";
            cin >>a>>b;
            s1.enQueue(a,b);
            cout << "Enqueued " << a << "\n";
            break;
        }
        case 2: {
            int dequeuedValue = s1.deQueue();
            if (dequeuedValue == INT_MIN) {
                cout << "Queue is empty, nothing to dequeue!\n";
            } else {
                cout << "Dequeued value: " << dequeuedValue << "\n";
            }
            break;
        }
        case 3: {
            s1.display();
            break;
        }
        case 4: {
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