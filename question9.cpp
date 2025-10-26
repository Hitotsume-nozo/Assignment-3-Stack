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
        if (top < capacity - 1) {
            arr[++top] = x;
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

    bool isEmpty() {
        return top == -1;
    }
};

void dailyTemperatures(int temps[], int n) {
    Stack s(n);
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && temps[s.peek()] <= temps[i]) {
            s.pop();
        }

        result[i] = s.isEmpty() ? 0 : s.peek() - i;
        s.push(i);
    }

    cout << "Output: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = 8;

    cout << "Input: [";
    for (int i = 0; i < n; i++) {
        cout << temps[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    dailyTemperatures(temps, n);
    return 0;
}