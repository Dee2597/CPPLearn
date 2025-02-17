#pragma once

/*

In C++, understanding the concepts of lvalues and rvalues is crucial for mastering the language, especially when dealing with references, move semantics, and resource management.


LValue
An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e., it has an address). Lvalues can appear on the left-hand side of an assignment.


RValue
An rvalue (read value) represents a temporary object or a value that does not have a persistent memory address. Rvalues can appear on the right-hand side of an assignment.

*/

//LValue Example

int x = 10; // 'x' is an lvalue
int* p = &x; // 'p' is an lvalue, and '&x' is an lvalue

//RValue Example

int y = 20; // 'y' is an lvalue
int z = x + y; // 'x + y' is an rvalue


//LValue Reference

int a = 5;
int& ref = a; // 'ref' is an lvalue reference to 'a'
ref = 10; // Modifies 'a' through 'ref'



//RValue Refrence
//Rvalue references are declared using the && operator and can bind to rvalues. They are primarily used to implement move semantics and perfect forwarding.


int&& rref = 5; // 'rref' is an rvalue reference to the temporary value '5'
rref = 10; // Modifies the temporary value


//Move Semantics

//Move semantics allow the resources owned by an rvalue to be moved rather than copied.This is useful for optimizing performance by avoiding unnecessary deep copies.


#include <iostream>
#include <vector>

class MyClass {
public:
    std::vector<int> data;

    MyClass() {
        std::cout << "Default constructor" << std::endl;
    }

    MyClass(const MyClass& other) {
        std::cout << "Copy constructor" << std::endl;
        data = other.data;
    }

    MyClass(MyClass&& other) noexcept {
        std::cout << "Move constructor" << std::endl;
        data = std::move(other.data);
    }
};

int main() {
    MyClass obj1;
    MyClass obj2 = obj1; // Calls copy constructor
    MyClass obj3 = std::move(obj1); // Calls move constructor
    return 0;
}
