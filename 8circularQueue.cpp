#include <iostream>
#define MAX 10
using namespace std;
class circularQueue
{
private:
    int arr[MAX], front, rear;

public:
    circularQueue()
    {
        front = 0;
        rear = 0;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return ((rear + 1) % MAX == front);
    }
    void enqueue(int k)
    {
        if (isFull())
        {
            cout << "queue is full";
            return;
        }
        rear = (rear + 1) % MAX;
        cout << "enqueue: " << k;
        arr[rear] = k;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty";
            return -1;
        }
        front = (front + 1) % MAX;
        cout << "dequeue integer: ";
        return arr[front];
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "queue is empty";
            return -1;
        }
        return arr[(front + 1) % MAX];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "nothing is in stack\n";
            return;
        }
        for (int i = (front + 1) % MAX; i != rear; i = (i + 1) % MAX)
            cout << arr[i] << " ";
        cout << arr[rear];
        cout << "\n";
    }
};
int main()
{
    circularQueue s1;
    int i = 0;
    cout << "to enqueue an integer type 1\n"
         << "to dequeue an integer type 2\n"
         << "to peak an integer type 3\n"
         << "to display circular queue type 4\n"
         << "to stop the queue type 5\n";
    while (i != 5)
    {
        cin >> i;
        switch (i)
        {
        case 1:
            int a;
            cin >> a;
            s1.enqueue(a);
            cout << "\n";
            break;
        case 2:
            cout << s1.dequeue() << "\n";
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
        }
    }
    return 0;
}