#pragma once


//Example Without Virtual Destructor



#include <iostream>

class Base {
public:
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // Only Base destructor is called
    return 0;
}


//Output: Base Destructor


//Example With Virtual Destructor

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // Both Base and Derived destructors are called
    return 0;
}

//output:
//Derived Destructor
//Base Destructor

