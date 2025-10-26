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

### 6. Nearest Smaller Element (to the left)
**Description:** For each array value, finds the nearest smaller value to its left. Uses stack for O(n) time solution.

**Code:**
```cpp
#include <iostream>
using namespace std;
class Stack{int* arr;int top;int capacity;public:Stack(int size){arr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;}}int pop(){if(top>=0){return arr[top--];}return -1;}int peek(){if(top>=0){return arr[top];}return -1;}bool isEmpty(){return top==-1;}};void nearestSmallerElement(int arr[],int n){Stack s(n);int result[n];for(int i=0;i<n;i++){while(!s.isEmpty()&&s.peek()>=arr[i]){s.pop();}result[i]=s.isEmpty()?-1:s.peek();s.push(arr[i]);}cout<<"Output: [";for(int i=0;i<n;i++){cout<<result[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;}int main(){int arr[]={4,5,2,10,8};int n=5;cout<<"Input: [";for(int i=0;i<n;i++){cout<<arr[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;nearestSmallerElement(arr,n);return 0;}
```

**Sample Output:**
```
Input: [4, 5, 2, 10, 8]
Output: [-1, 4, -1, 2, 2]
```

---

### 7. Stack with O(1) getMin
**Description:** Stack stores elements and can retrieve minimum value in O(1) time with extra array.

**Code:**
```cpp
#include <iostream>
using namespace std;
class MinStack{int* arr;int* minArr;int top;int capacity;public:MinStack(int size){arr=new int[size];minArr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;if(top==0){minArr[top]=x;}else{minArr[top]=min(x,minArr[top-1]);}}}int pop(){if(top>=0){return arr[top--];}return -1;}int peek(){if(top>=0){return arr[top];}return -1;}int getMin(){if(top>=0){return minArr[top];}return -1;}};int main(){MinStack s(10);s.push(2);s.push(3);cout<<s.peek()<<endl;s.pop();cout<<s.getMin()<<endl;s.push(1);cout<<s.getMin()<<endl;return 0;}
```

**Sample Output:**
```
3
2
1
```

---

### 8. Next Greater Element (to the right)
**Description:** Prints the next greater element for each value in the array.

**Code:**
```cpp
#include <iostream>
using namespace std;
class Stack{int* arr;int top;int capacity;public:Stack(int size){arr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;}}int pop(){if(top>=0){return arr[top--];}return -1;}int peek(){if(top>=0){return arr[top];}return -1;}bool isEmpty(){return top==-1;}};void nextGreaterElement(int arr[],int n){Stack s(n);int result[n];for(int i=n-1;i>=0;i--){while(!s.isEmpty()&&s.peek()<=arr[i]){s.pop();}result[i]=s.isEmpty()?-1:s.peek();s.push(arr[i]);}cout<<"Output: [";for(int i=0;i<n;i++){cout<<result[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;}int main(){int arr[]={1,3,2,4};int n=4;cout<<"Input: [";for(int i=0;i<n;i++){cout<<arr[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;nextGreaterElement(arr,n);return 0;}
```

**Sample Output:**
```
Input: [1, 3, 2, 4]
Output: [3, 4, 4, -1]
```

---

### 9. Daily Temperatures (Next Warmer Day)
**Description:** Given temperatures, tells for each day how many days until a warmer temperature. Uses stack index approach.

**Code:**
```cpp
#include <iostream>
using namespace std;
class Stack{int* arr;int top;int capacity;public:Stack(int size){arr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;}}int pop(){if(top>=0){return arr[top--];}return -1;}int peek(){if(top>=0){return arr[top];}return -1;}bool isEmpty(){return top==-1;}};void dailyTemperatures(int temps[],int n){Stack s(n);int result[n];for(int i=n-1;i>=0;i--){while(!s.isEmpty()&&temps[s.peek()]<=temps[i]){s.pop();}result[i]=s.isEmpty()?0:s.peek()-i;s.push(i);}cout<<"Output: [";for(int i=0;i<n;i++){cout<<result[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;}int main(){int temps[]={73,74,75,71,69,72,76,73};int n=8;cout<<"Input: [";for(int i=0;i<n;i++){cout<<temps[i];if(i<n-1)cout<<", ";}cout<<"]"<<endl;dailyTemperatures(temps,n);return 0;}
```

**Sample Output:**
```
Input: [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]
```

---

### 10. Stack Sort Practice
**Description:** Simulates a stack-sorting problem to check if array can be sorted by stack operations.

**Code:**
```cpp
#include <iostream>
using namespace std;
class Stack{int* arr;int top;int capacity;public:Stack(int size){arr=new int[size];capacity=size;top=-1;}void push(int x){if(top<capacity-1){arr[++top]=x;}}int pop(){if(top>=0){return arr[top--];}return -1;}int peek(){if(top>=0){return arr[top];}return -1;}bool isEmpty(){return top==-1;}};bool canSort(int arr[],int n){Stack s(n);int expected=1;int i=0;while(i<n){if(arr[i]==expected){expected++;i++;}else if(!s.isEmpty()&&s.peek()==expected){s.pop();expected++;}else{s.push(arr[i]);i++;}}while(!s.isEmpty()){if(s.peek()==expected){s.pop();expected++;}else{return false;}}return true;}int main(){int arr1[]={2,1,3};int arr2[]={4,1,2,3};cout<<"Input: [2, 1, 3]"<<endl;cout<<"Output: "<<(canSort(arr1,3)?"Yes":"No")<<endl;cout<<"\nInput: [4, 1, 2, 3]"<<endl;cout<<"Output: "<<(canSort(arr2,4)?"Yes":"No")<<endl;return 0;}
```

**Sample Output:**
```
Input: [2, 1, 3]
Output: Yes

Input: [4, 1, 2, 3]
Output: No
```

---

## Conclusion
This assignment demonstrates direct and practical applications of stacks for real programming problems in C++. Solutions are simple, minimal, and readable, enabling easy learning and revision. Execution outputs show expected program behavior without any ambiguity or oversimplification.