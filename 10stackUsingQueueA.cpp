#include <iostream>
#include <climits>
#define MAX 10
using namespace std;
class queue
{
private:
    int arr[MAX], front, rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return rear == MAX - 1;
    }
    void enqueue(int k)
    {
        if (isFull())
        {
            cout << "queue is full";
            return;
        }
        arr[++rear] = k;
    }
    int dequeue()
    {
        int a;
        if (isEmpty())
            return INT_MIN;
        front = front + 1;
        return arr[front];
        if (front == MAX)
            return INT_MAX;
    }
    int peek()
    {
        if (isEmpty())
            return INT_MIN;
        return arr[front + 1];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "nothing is in stack\n";
            return;
        }
        for (int i = rear; i >= front + 1; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
class Stack{
    queue Q1;
    queue Q2;
    public:
    void push(int item){
        Q2.enqueue(item);
        if(!Q1.isEmpty()){
            while(!Q1.isEmpty())
                Q2.enqueue(Q1.dequeue());
        }
        queue temp= Q1;
        Q1= Q2;
        Q2=temp;
    }
    int pop(){
        if (Q1.isEmpty())
        {
            cout << "nothing is in stack\n";
            return INT_MIN;
        }
        return Q1.dequeue();
    }
    int peek(){
        if (Q1.isEmpty())
        {
            cout << "nothing is in stack\n";
            return INT_MIN;
        }
        return Q1.peek();
    }
    void display(){
        if (Q1.isEmpty())
        {
            cout << "nothing is in stack\n";
            return;
        }
        Q1.display();
    }
};
int main(){
    Stack S;
    S.push(2);
    S.push(7);
    S.push(9);
    S.push(3);
    cout<<"pop: "<<S.pop()<<endl;
    cout<<"peek: "<<S.peek()<<endl;
    S.display();
}