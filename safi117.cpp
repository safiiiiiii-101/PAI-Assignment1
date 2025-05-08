#include <iostream>
#include <string>
using namespace std;

class OutOfBoundsException {};

template <typename T>
class SmartArray {
    T *arr;
    int size;
public:
    SmartArray(int s) : size(s) { arr = new T[size]; }
    ~SmartArray() { delete[] arr; }
    T& operator[](int index) {
        if (index < 0 || index >= size) throw OutOfBoundsException();
        return arr[index];
    }
};

int main() {
    try {
        SmartArray<int> intArr(5);
        cout << "Accessing index 2: " << intArr[2] << endl;
        cout << "Accessing index 5: " << intArr[5] << endl;
    } catch (OutOfBoundsException) {
        cout << "OutOfBoundsException caught: Invalid index access attempted!" << endl;
    }

    return 0;
}