#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class myqueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    myqueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Erorr full";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Erorr empty";
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
        return x;
    }

    int Peek() {
        if (isEmpty()) {
            cout << "Erorr empty";
            return -1;
        }
        else {
            return arr[front];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Erorr full";
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    myqueue r;
    r.enqueue(7);
    r.enqueue(8);
    r.enqueue(9);
    r.display();

    cout << r.Peek() << endl;
    r.display();

    r.dequeue();
    r.display();

    return 0;
}