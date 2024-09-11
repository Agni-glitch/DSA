#include <iostream>
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
            return INT16_MIN;
        front = front + 1;
        return arr[front];
        if (front == MAX)
            return INT16_MAX;
    }
    int peek()
    {
        if (isEmpty())
            return INT16_MIN;
        return arr[front + 1];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "nothing is in stack\n";
            return;
        }
        for (int i = front + 1; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main()
{
    queue s1;
    int i = 0;
    cout << "to enqueue an integer type 1\n"
         << "to dequeue an integer type 2\n"
         << "to peak an integer type 3\n"
         << "to display stack type 4\n"
         << "to stop the stack type 5\n";
    while (i != 5)
    {
        cin >> i;
        switch (i)
        {
        case 1:
            int a;
            cin >> a;
            s1.enqueue(a);
            cout << "enqueue " << a << "\n";
            break;
        case 2:
            cout << "popped integer: " << s1.dequeue() << "\n";
            break;
        case 3:
            cout << "peeked front: ";
            cout << s1.peek() << "\n";
            break;
        case 4:
            s1.display();
            break;
        case 5:
            cout << "exit";
            break;
        default:
            cout << "input Not found\n";
            break;
        }
    }
    return 0;
}