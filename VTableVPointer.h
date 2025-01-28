#pragma once

//VTABLE:
//   A VTable is a table of function pointers maintained per class that has virtual functions. 
//   It is used to resolve function calls at runtime.
//   Each class with virtual functions has its own VTable, which contains pointers to the virtual functions defined by that class.


//  VIRTUAL POINTER

// A VPointer (also known as VPTR) is a hidden pointer in each object of a class that has virtual functions.
//  This pointer points to the VTable of the class. 
// When a virtual function is called on an object, the VPointer is used to look up the function address in the VTable and call the correct function. 


#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
    virtual ~Base() = default; // Virtual destructor
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show(); // Calls Derived's show function
    delete b;
    return 0;
}



/*

VTable and VPointer in Action
•	VTable: The Base class has a VTable with a pointer to Base::show(). The Derived class has a VTable with a pointer to Derived::show().
•	VPointer: The Derived object has a VPointer that points to the Derived class's VTable.
Memory Layout

The memory layout of an object with virtual functions typically looks like this:


+-----------------+
| VPointer        | --> Points to VTable
+-----------------+
| Data Members    |
+-----------------+


VTable Layout
The VTable layout typically looks like this:


+-----------------+
| &Derived::show  | --> Function pointer to Derived's show function
+-----------------+
| &Base::~Base    | --> Function pointer to Base's destructor
+-----------------+


*/