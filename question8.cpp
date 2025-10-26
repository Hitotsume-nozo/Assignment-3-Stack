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

void nextGreaterElement(int arr[], int n) {
    Stack s(n);
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && s.peek() <= arr[i]) {
            s.pop();
        }

        result[i] = s.isEmpty() ? -1 : s.peek();
        s.push(arr[i]);
    }

    cout << "Output: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = 4;

    cout << "Input: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    nextGreaterElement(arr, n);
    return 0;
}