#include <iostream>
#include <climits>
#define MAX 5
using namespace std;
class myStack
{
    int arr[MAX];
    int top;
public:
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
            return INT_MIN;
        int k = arr[top--];
        return k;
    }
    int peek()
    {
        if (isEmpty())
            return INT_MIN;
        return arr[top];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "nothing is in stack";
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main()
{
    myStack s1;
    int i = 0;
    cout << "to push an integer type 1\n"
         << "to pop an integer type 2\n"
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
            s1.push(a);
            cout << "pushed " << a << "\n";
            break;
        case 2:
            s1.pop();
            cout << "popped 1 integer\n";
            break;
        case 3:
            cout << "peeked top: ";
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