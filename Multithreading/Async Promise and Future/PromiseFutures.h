#pragma once
// TOPIC: std::future and std::promise in threading.

// NOTES:
// 1. std::promise
//      a. Used to set values or exceptions.
// 2. std::future
//      a. Used to get values from promise.
//      b. Ask promise if the value is available.
//      c. Wait for the promise.



/*

romises and Futures are two related concepts in programming that help manage asynchronous operations.

Promise:

A Promise is a result object that is used to handle asynchronous operations. It represents a value that may not be available yet, but will be resolved at some point in the future.

A Promise can be in one of the following states:

- Pending: Initial state, neither fulfilled nor rejected.
- Fulfilled: Successful operation, the promise is resolved with a value.
- Rejected: Failed operation, the promise is rejected with an error.

Future:

A Future is a read-only reference to a result that may not be available yet. It is a placeholder for a value that will be available at some point in the future.


In other words, a Future is a container that holds a Promise. When the Promise is resolved or rejected, the Future is updated with the result


1. Direction: A Promise is a writeable object that can be resolved or rejected, while a Future is a read-only object that can only be observed.
2. State: A Promise can be in one of three states (pending, fulfilled, or rejected), while a Future is always in a pending state until the underlying Promise is resolved or rejected.
3. Usage: Promises are typically used to handle asynchronous operations, while Futures are used to observe the result of an asynchronous operation.
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

template <typename T>
class Future; //Forward Declaration


template <typename T>
class Promise
{

private:
	std::mutex m;
	std::condition_variable cv;
	T value{};
	bool ready;


public:
	Promise() : ready(false) {}


	Future<T> get_Future()
	{
		return Future<T>(this);
	}

	void setValue(T val)
	{
		std::lock_guard<std::mutex>m1(m);
		val = val;
		ready = true;
		cv.notify_one();
	}

	T get()
	{
		std::unique_lock<std::mutex> lock(m);
		cv.wait(lock, [&]() { return ready; });
		return value;
	}


};


template <typename T>
class Future
{

private:

	Promise<T>* promise;

public:
	Future(Promise<T>* promise) : promise(promise) {};

	int get()
	{
		return promise->get();
	}

};


int startPromise()
{
	Promise<int> promise;

	Future<int> future = promise.get_Future();

	std::thread([&promise]()
		{
			std::this_thread::sleep_for(std::chrono::seconds(2000));
			promise.setValue(40);
		}).detach();

		std::cout << "Waiting for the future to be ready..." << std::endl;
		int result = future.get();
		std::cout << "Result: " << result << std::endl;

		return 0;

}



//#include <iostream>
//#include <future>
//#include <thread>
//#include <chrono>
//
//int startPromise() {
//	std::promise<int> promise;
//	std::future<int> future = promise.get_future();
//
//	std::thread([&promise]() {
//		std::this_thread::sleep_for(std::chrono::seconds(2));
//		promise.set_value(40);
//		}).detach();
//
//		std::cout << "Waiting for the future to be ready..." << std::endl;
//		int result = future.get();
//		std::cout << "Result: " << result << std::endl;
//
//		return 0;
//}
//
//int main() {
//	startPromise();
//	return 0;
//}



