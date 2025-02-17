#pragma once


//The basic syntax of a lambda function is as follows :
//
//[capture](parameters) -> return_type {
//    // function body
//    };

//Components
//
//1.	Capture Clause : [capture]
//•	Specifies which variables from the surrounding scope are accessible inside the lambda.
//•	Examples : [x, &y] , [=](capture all by value), [&](capture all by reference).
//
//2.	Parameters : (parameters)
//•	The parameters that the lambda function takes, similar to regular function parameters.
//
//3.	Return Type : ->return_type
//•	Specifies the return type of the lambda function.This is optional and can often be inferred by the compiler.
//
//4.	Function Body : { // function body }
//    •	The code that defines what the lambda function does.



//Example 1: Capturing Specific Variables by Value and by Reference
//
//
//#include <iostream>
//
//int main() {
//        int a = 10;
//        int b = 20;
//
//        // Capture 'a' by value and 'b' by reference
//        auto lambda = [a, &b]() {
//            std::cout << "Inside lambda: a = " << a << ", b = " << b << std::endl;
//            // Modify 'b' inside the lambda
//            b = 30;
//            };
//
//        lambda();
//
//        std::cout << "Outside lambda: a = " << a << ", b = " << b << std::endl;
//
//        return 0;
//    }



//Example 2: Capturing All Variables by Value
//
//#include <iostream>
//
//int main() {
//    int x = 5;
//    int y = 10;
//
//    // Capture all variables by value
//    auto lambda = [=]() {
//        std::cout << "Inside lambda: x = " << x << ", y = " << y << std::endl;
//        // x and y are captured by value, so they cannot be modified inside the lambda
//        };
//
//    lambda();
//
//    std::cout << "Outside lambda: x = " << x << ", y = " << y << std::endl;
//
//    return 0;
//}


//Example 3: Capturing All Variables by Reference
//
//#include <iostream>
//
//int main() {
//    int x = 5;
//    int y = 10;
//
//    // Capture all variables by reference
//    auto lambda = [&]() {
//        std::cout << "Inside lambda: x = " << x << ", y = " << y << std::endl;
//        // Modify x and y inside the lambda
//        x = 15;
//        y = 20;
//        };
//
//    lambda();
//
//    std::cout << "Outside lambda: x = " << x << ", y = " << y << std::endl;
//
//    return 0;
//}
