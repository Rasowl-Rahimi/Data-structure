#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Error";
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Error";
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Array {
private:
    LinkedList list;

public:
    void add(int value) {
        list.append(value);
    }

    int get(int index) {
        return list.get(index);
    }

    void set(int index, int value) {
        list.set(index, value);
    }

    int size() {
        return list.getSize();
    }

    void display() {
        list.display();
    }
};

int main() {
    Array a;

    a.add(10);
    a.add(20);
    a.add(30);

    a.display(); // 10 20 30

    cout << "index 1 = " << a.get(1) << endl; // 20

    a.set(1, 25);
    a.display();

    cout << "Size : " << a.size() << endl;

    return 0;
}
