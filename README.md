# Lab Assignment 3

## Introduction
This assignment explores stack-based and array-based data structures in C++. Each question reinforces an essential stack concept or classic problem-solving technique.

---

## Questions, Solutions, and Outputs

### 1. Menu Driven Stack Operations
**Description:** Implements stack using array and supports push, pop, isEmpty, isFull, display, and peek.

**Code:**
```cpp
#include <iostream>
using namespace std;
class Stack {
 int* arr; int top; int capacity;
public:
 Stack(int size) { arr=new int[size]; capacity=size; top=-1; }
 void push(int x) { if(isFull()){cout<<"Stack Overflow"<<endl;return;} arr[++top]=x; cout<<"Pushed "<<x<<endl; }
 int pop() { if(isEmpty()){cout<<"Stack Underflow"<<endl;return -1;} return arr[top--]; }
 bool isEmpty(){return top==-1;}
 bool isFull(){return top==capacity-1;}
 void display(){if(isEmpty()){cout<<"Stack is empty"<<endl; return;} cout<<"Stack elements: "; for(int i=0;i<=top;i++){cout<<arr[i]<<" ";} cout<<endl;}
 int peek(){if(isEmpty()){cout<<"Stack is empty"<<endl;return -1;} return arr[top];}
};
int main(){ Stack s(5); int choice,value; while(true){cout<<"\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\nChoice: ";cin>>choice; switch(choice){case 1:cout<<"Enter value: ";cin>>value;s.push(value);break;case 2:value=s.pop();if(value!=-1)cout<<"Popped: "<<value<<endl;break;case 3:cout<<(s.isEmpty()?"Stack is empty":"Stack is not empty")<<endl;break;case 4:cout<<(s.isFull()?"Stack is full":"Stack is not full")<<endl;break;case 5:s.display();break;case 6:value=s.peek();if(value!=-1)cout<<"Top element: "<<value<<endl;break;case 7:return 0;default:cout<<"Invalid choice"<<endl; } } return 0; }
```

**Sample Output:**
```
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 1
Enter value: 10
Pushed 10
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 1
Enter value: 20
Pushed 20
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 1
Enter value: 30
Pushed 30
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 5
Stack elements: 10 20 30
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 6
Top element: 30
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 2
Popped: 30
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 5
Stack elements: 10 20
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 3
Stack is not empty
1. Push
2. Pop
3. isEmpty
4. isFull
5. Display
6. Peek
7. Exit
Choice: 7
```

---

### 2. Reverse String Using Stack
**Description:** Reverses a string by pushing each character to stack.

**Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;
class Stack{char* arr;int top;int capacity;public:Stack(int size){arr=new char[size];capacity=size;top=-1;}void push(char x){if(top<capacity-1){arr[++top]=x;}}char pop(){if(top>=0){return arr[top--];}return '\0';}bool isEmpty(){return top==-1;}};string reverseString(string str){Stack s(str.length());for(int i=0;i<str.length();i++){s.push(str[i]);}string reversed="";while(!s.isEmpty()){reversed+=s.pop();}return reversed;}int main(){string str="DataStructure";cout<<"Original: "<<str<<endl;cout<<"Reversed: "<<reverseString(str)<<endl;return 0;}
```

**Sample Output:**
```
Original: DataStructure
Reversed: erutcurtSataD
```

---

### 3. Balanced Parentheses Checker
**Description:** Checks if an expression contains balanced parentheses, brackets, and braces.

**Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;
class Stack{char* arr;int top;int capacity;public:Stack(int size){arr=new char[size];capacity=size;top=-1;}void push(char x){if(top<capacity-1){arr[++top]=x;}}char pop(){if(top>=0){return arr[top--];}return '\0';}char peek(){if(top>=0){return arr[top];}return '\0';}bool isEmpty(){return top==-1;}};bool isBalanced(string expr){Stack s(expr.length());for(int i=0;i<expr.length();i++){char ch=expr[i];if(ch=='('||ch=='{'||ch=='['){s.push(ch);}else if(ch==')'||ch=='}'||ch==']'){if(s.isEmpty())return false;char top=s.pop();if((ch==')'&&top!='(')||(ch=='}'&&top!='{')||(ch==']'&&top!='[')){return false;}}}return s.isEmpty();}int main(){string expr1="{[()]}";string expr2="{[(])}";cout<<expr1<<" is "<<(isBalanced(expr1)?"balanced":"not balanced")<<endl;cout<<expr2<<" is "<<(isBalanced(expr2)?"balanced":"not balanced")<<endl;return 0;}
```

**Sample Output:**
```
{[()]} is balanced
{[(])} is not balanced
```

---

### 4. Infix to Postfix
**Description:** Converts an infix expression to postfix notation using stack.

**Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;
class Stack{char* arr;int top;int capacity;public:Stack(int size){arr=new char[size];capacity=size;top=-1;}void push(char x){if(top<capacity-1){arr[++top]=x;}}char pop(){if(top>=0){return arr[top--];}return '\0';}char peek(){if(top>=0){return arr[top];}return '\0';}bool isEmpty(){return top==-1;}};int precedence(char op){if(op=='+'||op=='-')return 1;if(op=='*'||op=='/')return 2;if(op=='^')return 3;return 0;}string infixToPostfix(string infix){Stack s(infix.length());string postfix="";for(int i=0;i<infix.length();i++){char ch=infix[i];if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){postfix+=ch;}else if(ch=='('){s.push(ch);}else if(ch==')'){while(!s.isEmpty()&&s.peek()!='('){postfix+=s.pop();}s.pop();}else{while(!s.isEmpty()&&precedence(s.peek())>=precedence(ch)){postfix+=s.pop();}s.push(ch);}}while(!s.isEmpty()){postfix+=s.pop();}return postfix;}int main(){string infix="a+b*(c^d-e)^(f+g*h)-i";cout<<"Infix: "<<infix<<endl;cout<<"Postfix: "<<infixToPostfix(infix)<<endl;return 0;}
```

**Sample Output:**
```
Infix: a+b*(c^d-e)^(f+g*h)-i
Postfix: abcd^e-fgh*+^*+i-
```

---

### 5. Evaluate Postfix Expression
**Description:** Evaluates a postfix mathematical expression using stack.

**Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;
class Stack{int* arr;int top;int capacity;public:Stack(int size){arr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;}}int pop(){if(top>=0){return arr[top--];}return 0;}bool isEmpty(){return top==-1;}};int evaluatePostfix(string postfix){Stack s(postfix.length());for(int i=0;i<postfix.length();i++){char ch=postfix[i];if(ch>='0'&&ch<='9'){s.push(ch-'0');}else{int val2=s.pop();int val1=s.pop();switch(ch){case '+':s.push(val1+val2);break;case '-':s.push(val1-val2);break;case '*':s.push(val1*val2);break;case '/':s.push(val1/val2);break;}}}return s.pop();}int main(){string postfix="231*+9-";cout<<"Postfix: "<<postfix<<endl;cout<<"Result: "<<evaluatePostfix(postfix)<<endl;return 0;}
```

**Sample Output:**
```
Postfix: 231*+9-
Result: -4
```
---

## Conclusion
This assignment demonstrates direct and practical applications of stacks for real programming problems in C++. Solutions are simple, minimal, and readable, enabling easy learning and revision. Execution outputs show expected program behavior without any ambiguity or oversimplification.
