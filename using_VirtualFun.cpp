#include <iostream>
using namespace std;

class InvalidSwapException : public exception {
public:
    InvalidSwapException() {
        cout << "Invalid swap operation attempted." << endl;
    }
};

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    void swap(Data& other) {
        if (other.value == value) {
            throw InvalidSwapException();
        }

        int temp = value;
        value = other.value;
        other.value = temp;
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    try {
        Data a(10);
        Data b(20);

        cout << "Before swapping:" << endl;
        a.print();
        b.print();

        a.swap(b);

        cout << "After swapping:" << endl;
        a.print();
        b.print();
    } catch (InvalidSwapException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
