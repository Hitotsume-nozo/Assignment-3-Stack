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

bool canSort(int arr[], int n) {
    Stack s(n);
    int expected = 1;
    int i = 0;

    while (i < n) {
        if (arr[i] == expected) {
            expected++;
            i++;
        }
        else if (!s.isEmpty() && s.peek() == expected) {
            s.pop();
            expected++;
        }
        else {
            s.push(arr[i]);
            i++;
        }
    }

    while (!s.isEmpty()) {
        if (s.peek() == expected) {
            s.pop();
            expected++;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int arr1[] = {2, 1, 3};
    int arr2[] = {4, 1, 2, 3};

    cout << "Input: [2, 1, 3]" << endl;
    cout << "Output: " << (canSort(arr1, 3) ? "Yes" : "No") << endl;

    cout << "\nInput: [4, 1, 2, 3]" << endl;
    cout << "Output: " << (canSort(arr2, 4) ? "Yes" : "No") << endl;

    return 0;
}