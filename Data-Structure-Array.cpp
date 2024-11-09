#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class MyArray {
private:
    int arr[MAX_SIZE];
    int size;

public:
    MyArray() {
        size = 0;
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (size == MAX_SIZE) {
            cout << "Array is full!" << endl;
            return;
        }

        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        size++;
    }

    int Delete_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                return i;
            }
        }
        return -1;
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
        if (size == MAX_SIZE) {
            cout << "Array is full!" << endl;
            return;
        }
        arr[size++] = value;
    }

    void Reverse() {
        int start = 0;
        int end = size - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    int Search_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    MyArray myArray;

    myArray.Insert(0, 10);
    myArray.Insert(1, 20);
    myArray.Insert(2, 30);
    myArray.Append(40);
    myArray.Display();

    myArray.Delete_By_Value(40);
    myArray.Display();

    cout << "Index of 30: " << myArray.Search_By_Value(30) << endl;

    myArray.Reverse();
    myArray.Display();

    return 0;
}
