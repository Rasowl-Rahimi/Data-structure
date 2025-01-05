#include <iostream>

using namespace std;

const int SIZE = 100;

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE -1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
        else {
            cout << "Error" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        else {
            cout << "Error" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            cout << "Error" << endl;
            return -1;
        }
    }
};

class Queue {
private:
    Stack mainStack; 
    Stack secStack;

public:
    void enqueue(int x) {
        mainStack.push(x);
    }

    void dequeue() {
        if (mainStack.isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        while (!mainStack.isEmpty()) {
            secStack.push(mainStack.pop());
        }

        secStack.pop();

        while (!secStack.isEmpty()) {
            mainStack.push(secStack.pop());
        }
    }

    int front() {
        if (mainStack.isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        while (!mainStack.isEmpty()) {
            secStack.push(mainStack.pop());
        }

        int frontElement = secStack.peek(); 


        while (!secStack.isEmpty()) 
        {
            mainStack.push(secStack.pop());
        }

        return frontElement; 
    }

    bool isEmpty() {
        return mainStack.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Stack tempStack; 
        while (!mainStack.isEmpty()) {
            tempStack.push(mainStack.pop());
        }

        while (!tempStack.isEmpty()) {
            int e = tempStack.pop();
            cout << e << " ";
            mainStack.push(e); 
        }

    }
};

int main() {
    Queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);

    cout << "Front : " << s.front() << endl; 

    s.dequeue();
    s.front();

    s.display(); 
}
