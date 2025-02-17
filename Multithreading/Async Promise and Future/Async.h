#pragma once


/*
std::async and std::launch::deferred are two related concepts in C++ that deal with asynchronous execution.

std::async is a function that executes a given function asynchronously, returning a std::future object that represents the result of the asynchronous operation.

std::launch::deferred is a launch policy that can be passed to std::async to specify how the asynchronous operation should be executed.

When std::launch::deferred is used with std::async, the asynchronous operation is not executed immediately.Instead, 
it is executed lazily, only when the std::future object returned by std::async is actually waited on or queried for its result.

*/


#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono;

int asyncFunction() {
    std::cout << "Async function executed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int startLaunchAsync() {
    auto startTime = std::chrono::high_resolution_clock::now(); // Add parentheses to call the function
    std::future<int> future = std::async(std::launch::async, asyncFunction);
    std::cout << "Main function continued" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int result = future.get(); // asyncFunction is executed here
    auto endTime = std::chrono::high_resolution_clock::now(); // Add parentheses to call the function

    auto ThreadExecutionTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime); // Specify the type for duration_cast

    std::cout << "Time Taken: " << ThreadExecutionTime.count()/1000000<<" seconds" << std::endl; // Use count() to get the value
    return 0;
}


int startLaunchDeferred() {
    auto startTime = std::chrono::high_resolution_clock::now(); // Add parentheses to call the function
    std::future<int> future = std::async(std::launch::deferred, asyncFunction);
    std::cout << "Main function continued" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int result = future.get(); // asyncFunction is executed here
    auto endTime = std::chrono::high_resolution_clock::now(); // Add parentheses to call the function

    auto ThreadExecutionTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime); // Specify the type for duration_cast

    std::cout << "Time Taken: " << ThreadExecutionTime.count() / 1000000 << " seconds" << std::endl; // Use count() to get the value
    return 0;
}



/*

std::async, std::promise, and std::future are three related concepts in C++ that deal with asynchronous programming.
While std::promise and std::future provide a way to synchronize the production and consumption of a value, std::async provides a way to execute a function asynchronously.

Here are some reasons why std::async is required even when using std::promise and std::future:

1. Asynchronous execution: std::async allows you to execute a function asynchronously,
which means that the function is executed in a separate thread or process. This is useful when you want to perform a time-consuming operation without blocking the main thread.

2. Simplifies thread management: When using std::promise and std::future directly, you need to manage threads manually, which can be error-prone and complex.
std::async simplifies thread management by creating and managing threads automatically.

3. Provides a higher-level abstraction: std::async provides a higher-level abstraction than std::promise and std::future. 
It allows you to focus on the asynchronous operation itself, rather than the underlying synchronization mechanisms.

4. Supports lazy evaluation: std::async supports lazy evaluation, which means that the asynchronous operation is only executed when its result is actually needed. This can be useful for improving performance by avoiding unnecessary computations.

5. Provides better exception handling: std::async provides better exception handling than std::promise and std::future. If an exception occurs during the asynchronous operation, std::async will propagate the exception to the caller, making it easier to handle errors.


*/