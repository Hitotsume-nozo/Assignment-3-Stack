#include <iostream>
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
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s(5);
    int choice, value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != -1) cout << "Popped: " << value << endl;
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                value = s.peek();
                if (value != -1) cout << "Top element: " << value << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}