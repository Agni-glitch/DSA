#include <iostream>
#include <climits>
#define MAX 10
using namespace std;
class myStack
{
public:
    int arr[MAX];
    int top;
    myStack()
    {
        top = -1;
    }
    int isEmpty()
    {
        return top == -1;
    }
    int isFull()
    {
        return top == MAX - 1;
    }
    void push(int k)
    {
        if (isFull())
            return;
        arr[++top] = k;
    }
    int pop()
    {
        if (isEmpty())
            return -1;
        int k = arr[top--];
        return k;
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "nothing is in stack";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
class queue{
myStack S1;
myStack S2;
public:
void enqueue(int x){
    S1.push(x);
}
int dequeue(){
    if(S1.isEmpty()&&S2.isEmpty()){
        cout<<"queue is empty.";
        return INT16_MIN;
    }
    if (S2.isEmpty())
    {
        while (!S1.isEmpty())
        {
            S2.push(S1.pop());
        }
    }
    int topVal=S2.pop();
    return topVal;
}
void display(){
    if(S1.isEmpty()&&S2.isEmpty()){
        cout<<"queue is empty.";
        return;
    }
    if (S2.isEmpty())
    {
        while (!S1.isEmpty())
        {
            S2.push(S1.pop());
        }
    }
    S2.display();
}
bool isEmpty(){
    if(S1.isEmpty()&&S2.isEmpty())
        return true;
    return false; 
}
};
int main() {
    queue Q;
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(8);
    cout<<"dequeue: "<<Q.dequeue()<<endl;
    cout<<"dequeue: "<<Q.dequeue()<<endl;
    Q.display();
    return 0;
}