#include <iostream>
#include <cstring> // For strlen() function
using namespace std;
#define MAX 50 // Maximum size of the stack
class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return -1;
}
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
char prefix[MAX];     // Array to store the prefix expression
void infixToPrefix(const char* infix) {
    Stack stack;           // Stack to store operators
    int j = 0;             // Index for postfix array
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isOperand(c)) {
            prefix[j++] = c; // Append operands directly to prefix expression
        } else if (c == ')') {
            stack.push(c); // Push '(' onto stack
        } else if (c == '(') {
            while (!stack.isEmpty() && stack.peek() != ')') {
                prefix[j++] = stack.pop(); // Pop from stack until '(' is found
            }
            stack.pop(); // Pop '(' from stack
        } else if(c=='^'){ // Operator found
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                prefix[j++] = stack.pop(); // Pop higher precedence operators
            }
            stack.push(c); // Push current operator onto stack
        }else{
            while (!stack.isEmpty() && precedence(stack.peek()) > precedence(c)) {
                prefix[j++] = stack.pop(); // Pop higher or equal precedence operators
            }
            stack.push(c); // Push current operator onto stack
        }
    }
    while (!stack.isEmpty()) {
        prefix[j++] = stack.pop(); // Pop remaining operators from stack
    }
    prefix[j] = '\0'; // Null-terminate the prefix string
}
int main() {
    char infix[MAX];
    cout << "Enter an infix expression: ";
    cin >> infix;
    reverse(infix);
    infixToPrefix(infix);
    reverse(prefix);
    cout<<prefix;
    return 0;
}
