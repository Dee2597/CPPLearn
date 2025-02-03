#pragma once

//Why use Mutex | What is Race condition and How to solve | What is critical section

//Mutex : Mutual Exclusion

//RACE CONDITION
//Race condition is a situvation where two or more threads/Process happened to change a common data at the same time
// if there is a race condition then we have to protect it and the protected section is critical section

//MUTEX
//mutex is used avoid race condition
//we use lock(), unlock()


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int myamount = 0;
std::mutex m;

void addmoney()
{
	m.lock();
	++myamount;
	m.unlock();
}


int start()
{
	std::thread t1(addmoney);
	std::thread t2(addmoney);

	t1.join();
	t2.join();

	std::cout << "the amount is: " << myamount << endl;

	return 0;
}