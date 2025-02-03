#pragma once
// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition


#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;
int balance = 0;

void addMoney(int Money)
{
	std::lock_guard<mutex>lg(m);
	balance += Money;
	cout << "Amount Added current balance is: " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int money)
{
	std::unique_lock<mutex>ul(m);
	auto timeout = std::chrono::system_clock::now() + std::chrono::seconds(5);
	cv.wait_until(ul, timeout, [] { return (balance != 0); });
	if (balance >= money)
	{
		balance -= money;
		cout << "Amount Deducted : " << money << endl;

	}
	else
	{
		cout << "Amount Can't be Deducted current balance is less than: " << money << endl;
	}

	cout << "The current Balance is: " << balance << endl;

}


int start()
{
	std::thread t1(withdrawMoney, 500);
	std::thread t2(addMoney, 0);

	t1.join();
	t2.join();

	return 0;
}
