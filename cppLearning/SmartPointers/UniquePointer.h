// TOPIC: Unique Pointer In C++

// NOTES:
// 0. unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
//    when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use -> and * on the object of unique_ptr, 
//    because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.

// OPERATIONS:
// release, reset, swap, get, get_deleter.


// PROGRAM: 

#include<iostream>
#include<memory>
using namespace std;

class Foo {
    int x;
public:
    explicit Foo(int x) : x{ x } {}
    int getX() { return x; }
    ~Foo() { cout << "Foo Dest" << endl; }
};

int main() {

    // Foo *f = new Foo(10);
    // cout << f->getX() << endl;

    std::unique_ptr<Foo> p(new Foo(10));
    unique_ptr<Foo> p2 = make_unique<Foo>(20);

    cout << p->getX() << endl;
    cout << (*p2).getX() << endl;

    //p1 = p2 //FAIL: because can not copy ownership
    unique_ptr<Foo> p3 = std::move(p2);

    Foo* praw = p3.get(); // return raw pointer

    Foo* p4 = p3.release(); // unique ptr set to null ptr

    p2.reset(p4);   //p2 managed objectreset to p4 and p2 object get deleted



    return 0;
}