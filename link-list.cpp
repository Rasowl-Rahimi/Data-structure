#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value; 
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr; 
        size = 0;
    }

    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            cout << "ERROR";
        }

        Node* newnode = new Node(data);

        if (index == 0) {
            newnode->next = head;
            head = newnode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        size++;
    }

    void InsertAtEnd(int data) {  // :)
        InsertAtIndex(data, size);
    }

    void InsertAtBegin(int data) { //:)
        InsertAtIndex(data, 0);
    }

    void UpdateNode(int data, int index) {
        if (index < 0 || index >= size) {
            cout << "ERROR";
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = data;
    }

    int RemoveNodeAtIndex(int index) {

        Node* removedNode;
        int removedData;

        if (index == 0) {
            removedNode = head;
            head = head->next;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            removedNode = current->next;
            current->next = removedNode->next;
        }

        removedData = removedNode->data;
        delete removedNode;
        size--;
        return removedData;
    }

    int RemoveNodeAtEnd() {
        return RemoveNodeAtIndex(size - 1);
    }

    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }

    int SizeOfList() {
        return size;
    }

    void Concatenate(LinkedList& other) {
        Node* current = other.head;
        while (current != nullptr) {
            InsertAtEnd(current->data);
            current = current->next;
        }
    }

    void Display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void invert() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next; 
            current->next = prev; 
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    return 0;
}