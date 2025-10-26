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

void nearestSmallerElement(int arr[], int n) {
    Stack s(n);
    int result[n];

    for (int i = 0; i < n; i++) {
        while (!s.isEmpty() && s.peek() >= arr[i]) {
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
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;

    cout << "Input: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    nearestSmallerElement(arr, n);
    return 0;
}