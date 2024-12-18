#include <iostream>

using namespace std;

const int MAX_SIZE = 200; 

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Error !" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed in stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error !" << endl;
        }
        int x = arr[top--];
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error !" << endl;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << "popped from stack" << endl;

    cout << "Top element is " << s.peek() << endl;
}