#include <iostream>
#include <string>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x) {
        if (top < capacity - 1) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return 0;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string postfix) {
    Stack s(postfix.length());

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix = "231*+9-";
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}