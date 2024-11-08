#include <iostream>

using namespace std;

class Array {
private:
    int* arr;
    int size;
    int capacity;

public:
    Array() {
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (size == capacity) {
            int* temp = new int[2 * capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }

        
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

      
        arr[index] = value;

        size++;
    }

    int Delete_By_Value(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }

        return index;
    }

    void Delete_By_Index(int index) {
     
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void Display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Append(int value) {
        Insert(size, value);
    }

    void Reverse() {
        for (int i = 0; i < size / 2; i++) {
            swap(arr[i], arr[size - i - 1]);
        }
    }

    int Search_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Array arr;
    
    return 0;
}
