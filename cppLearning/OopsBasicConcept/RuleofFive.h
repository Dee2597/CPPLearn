#pragma once

/*

In C++, the "Rule of Five" is a set of guidelines that help developers manage resource ownership and avoid common pitfalls related to object copying and assignment.
These rules are particularly important when dealing with classes that manage dynamic memory or other resources. 
The Rule of Five states that if a class defines any one of the following five special member functions, it should probably explicitly define all five:
1.	Destructor
2.	Copy Constructor
3.	Copy Assignment Operator
4.	Move Constructor
5.	Move Assignment Operator



•	Destructor: Cleans up resources.
•	Copy Constructor: Creates a copy of an object.
•	Copy Assignment Operator: Copies the contents of one object to another existing object.
•	Move Constructor: Transfers resources from a temporary object to a new object.
•	Move Assignment Operator: Transfers resources from a temporary object to an existing object.

*/


#include <iostream>
#include <utility>

class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void print() const {
        if (data) {
            std::cout << "Value: " << *data << std::endl;
        }
        else {
            std::cout << "No data" << std::endl;
        }
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Copy constructor
    MyClass obj3 = std::move(obj1); // Move constructor

    obj2.print();
    obj3.print();
    obj1.print(); // obj1 is in a valid but unspecified state

    return 0;
}
