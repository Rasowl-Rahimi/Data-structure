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
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Erorr full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Erorr empty" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Erorr empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void reverseQueue() {
        if (isEmpty())
            return;

        int temp;

        int start = front;
        int end = rear;

        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Erorr empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    myqueue r;
    r.enqueue(10);
    r.enqueue(20);
    r.display();
    cout << r.peek() << endl;

    r.dequeue();
    r.display();

    r.enqueue(30);
    r.reverseQueue();
    r.display();
}