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

    bool isEmpty() {
        return top == -1;
    }
};

string reverseString(string str) {
    Stack s(str.length());
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }
    return reversed;
}

int main() {
    string str = "DataStructure";
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString(str) << endl;
    return 0;
}