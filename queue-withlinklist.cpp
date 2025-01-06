#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queuewithlinklist {
private:
    Node* front;
    Node* rear;

public:
    Queuewithlinklist() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queuewithlinklist q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); 

    q.dequeue();
    q.display(); 

    return 0;
}