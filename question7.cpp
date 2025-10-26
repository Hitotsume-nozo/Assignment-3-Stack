#include <iostream>
using namespace std;

class MinStack {
    int* arr;
    int* minArr;
    int top;
    int capacity;
public:
    MinStack(int size) {
        arr = new int[size];
        minArr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x) {
        if (top < capacity - 1) {
            arr[++top] = x;
            if (top == 0) {
                minArr[top] = x;
            } else {
                minArr[top] = min(x, minArr[top - 1]);
            }
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1;
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return -1;
    }

    int getMin() {
        if (top >= 0) {
            return minArr[top];
        }
        return -1;
    }
};

int main() {
    MinStack s(10);

    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.push(1);
    cout << s.getMin() << endl;

    return 0;
}