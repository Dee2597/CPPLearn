#pragma once

#include <iostream>

using namespace std;

//Functors, also known as function objects, are objects that can be treated as though they are functions or function pointers.
//They are instances of classes that have the operator() defined.Functors are used to encapsulate a function within an object, allowing the object to maintain state.


//#include <vector>
//#include <algorithm>
//
//// Functor class
//class MultiplyBy
//{
//    int factor;
//
//public:
//    MultiplyBy(int f) : factor(f) {}
//
//    // Overloading the function call operator
//    void operator()(int& n) const
//    {
//        n *= factor;
//    }
//};
//
//int main()
//{
//    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
//    int factor = 2;
//
//    // Create a functor instance
//    MultiplyBy multiplyBy(factor);
//
//    // Use the functor with std::for_each
//    std::for_each(numbers.begin(), numbers.end(), multiplyBy);
//
//    // Print the modified vector
//    for (int n : numbers)
//    {
//        std::cout << n << " ";
//    }
//
//    return 0;
//}





//#include <vector>
//#include <algorithm>
//
//// Functor class
//class CountIfGreaterThan
//{
//    int threshold;
//    int count;
//
//public:
//    CountIfGreaterThan(int t) : threshold(t), count(0) {}
//
//    // Overloading the function call operator
//    void operator()(int n)
//    {
//        if (n > threshold)
//        {
//            ++count;
//        }
//    }
//
//    // Function to get the count
//    int getCount() const
//    {
//        return count;
//    }
//};
//
//int main()
//{
//    std::vector<int> numbers = { 1, 5, 8, 10, 12, 3, 7, 9 };
//    int threshold = 6;
//
//    // Create a functor instance
//    CountIfGreaterThan countIfGreaterThan(threshold);
//
//    // Use the functor with std::for_each
//    std::for_each(numbers.begin(), numbers.end(), countIfGreaterThan);
//
//    // Get the count of elements greater than the threshold
//    int count = countIfGreaterThan.getCount();
//
//    std::cout << "Number of elements greater than " << threshold << ": " << count << std::endl;
//
//    return 0;
//}
