#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }

    void push(char x) {
        if (top < capacity - 1) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(string expr) {
    Stack s(expr.length());

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << expr1 << " is " << (isBalanced(expr1) ? "balanced" : "not balanced") << endl;
    cout << expr2 << " is " << (isBalanced(expr2) ? "balanced" : "not balanced") << endl;

    return 0;
}