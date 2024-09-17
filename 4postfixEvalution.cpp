#include <iostream>
#include <climits>
#include <cstring> // For strlen() function
#include <cctype>  // For isdigit() function
using namespace std;
#define MAX 100 // Maximum size of the stack
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return INT_MIN;
    }
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return INT_MIN;
    }
};
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}
int evaluatePostfix(const char* postfix) {
    Stack stack; // Stack to store operands
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert character to integer
        }
        else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '^':
                    stack.push(power(operand1,operand2));
                    break;
                default:
                    cout << "Invalid operator encountered: " << ch <<endl;
                    return INT_MIN;
            }
        }
    }
    return stack.pop();
}
int main() {
    char postfix[MAX];
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result <<endl;
    return 0;
}