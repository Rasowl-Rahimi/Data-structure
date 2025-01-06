#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class TwoWayLL {
private:
    Node* head;
    Node* tail;
    int size;

public:
    TwoWayLL() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtIndex(int index, int data) {
        Node* new_node = new Node(data);

        if (index == 0) {
            if (!head) {
                head = new_node;
                tail = new_node;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        else if (index == size) {
            new_node->prev = tail;
            if (tail) {
                tail->next = new_node;
            }
            tail = new_node;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
        size++;
    }

    void insertAtBegin(int data) {
        insertAtIndex(0, data);
    }

    void insertAtEnd(int data) {
        insertAtIndex(size, data);
    }

    void updateNode(int index, int data) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = data;
    }

    int removeNodeAtIndex(int index) {
        int data;
        if (size == 1) {
            data = head->data;
            delete head; 
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0) {
            data = head->data;
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp; 
        }
        else if (index == size - 1) {
            data = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp; 
        }
        else {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            data = current->data;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current; 
        }

        size--;
        return data;
    }

    int removeNodeAtBegin() {
        return removeNodeAtIndex(0);
    }

    int removeNodeAtEnd() {
        return removeNodeAtIndex(size - 1);
    }

    int sizeOfList() const {
        return size;
    }

    void invert() {
        Node* current = head;
        Node* temp = nullptr;
        tail = head; 
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; 
        }
        if (temp) {
            head = temp->prev; 
        }
    }

    void concatenate(TwoWayLL& linked_list) {
        if (!head) {
            head = linked_list.head;
            tail = linked_list.tail;
        }
        else {
            tail->next = linked_list.head;
            if (linked_list.head) {
                linked_list.head->prev = tail;
            }
            tail = linked_list.tail;
        }
        size += linked_list.size;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }
};

int main() {
    TwoWayLL list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();
    cout<<endl

    list.insertAtBegin(0);
    list.display();
    cout << endl;

    list.removeNodeAtIndex(1);
    list.display();
    cout << endl;

    list.invert();
    list.display();
}