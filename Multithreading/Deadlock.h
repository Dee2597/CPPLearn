#pragma once

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1, m2;

void thread1()
{
	m1.lock();
	m2.lock();
	cout << "critical Section of Thread1()" << endl;
	m1.unlock();
	m2.unlock();

}


void thread2()
{
	m2.lock();
	m1.lock();
	cout << "critical section for thread2()" << endl;
	m2.unlock();
	m1.unlock();
}


int start()
{
	std::thread t1(thread1);
	std::thread t2(thread2);

	t1.join();
	t2.join();

	return 0;

}