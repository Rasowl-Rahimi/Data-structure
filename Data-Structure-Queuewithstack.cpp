#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> mainStack;
    stack<int> secStack;

public:
    void enqueue(int x) {
        mainStack.push(x);
    }

    void dequeue() {
        if (mainStack.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

       
        while (!mainStack.empty()) {
            secStack.push(mainStack.top());
            mainStack.pop();
        }

        
        secStack.pop();

        
        while (!secStack.empty()) {
            mainStack.push(secStack.top());
            secStack.pop();
        }
    }

    int front() {
        if (mainStack.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

       
        while (!mainStack.empty()) {
            secStack.push(mainStack.top());
            mainStack.pop();
        }

        int frontElement = secStack.top();

        
        while (!secStack.empty()) {
            mainStack.push(secStack.top());
            secStack.pop();
        }

        return frontElement;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    return 0;
}