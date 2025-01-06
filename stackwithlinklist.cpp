#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        node* newNode = new node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        int data = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek();
}