
/*

A semaphore is a design pattern that provides a simple way to control access to a shared resource by multiple threads or processes.
It acts as a gatekeeper, allowing only a certain number of threads or processes to access the resource at any given time.

Here's a breakdown of how semaphores work:

Key components:

1. Semaphore variable: An integer variable that keeps track of the number of available slots or resources.
2. Acquire operation: A thread or process attempts to acquire the semaphore by decrementing the semaphore variable. 
If the variable is greater than 0, the thread or process is allowed to proceed. If the variable is 0, the thread or process is blocked until the semaphore is released.
3. Release operation: A thread or process releases the semaphore by incrementing the semaphore variable. This allows another thread or process to acquire the semaphore.

Types of semaphores:

1. Binary semaphore: A semaphore that can be in one of two states: 0 (locked) or 1 (unlocked).
2. Counting semaphore: A semaphore that can be in any state between 0 and a maximum value, representing the number of available resources.

Example use cases:

1. Resource allocation: A semaphore can be used to manage access to a shared resource, such as a printer or a network connection.
2. Thread synchronization: A semaphore can be used to synchronize threads, ensuring that only a certain number of threads can access a shared resource at any given time.
3. Producer-consumer problem: A semaphore can be used to solve the producer-consumer problem, where multiple producers and consumers share a common buffer.

*/




#pragma once
#include <iostream>
#include <thread>
#include <semaphore> // Include semaphore header
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <atomic>


class Counting_SemaPhore
{
private:
    std::atomic<int> count = 0;
    std::condition_variable cv;
    std::mutex m;

public:

    Counting_SemaPhore(int count) : count(count){}

    void acquire()
    {
        std::unique_lock<std::mutex> lock(m);

        while (count == 0)
        {
            cv.wait(lock);
        }

        --count;
    }

    void release()
    {   
        std::lock_guard<std::mutex> lock(m);
        ++count;
        cv.notify_one();
    }
};


class Binary_SemaPhore
{

private:
    bool flag = false;
    std::condition_variable cv;
    std::mutex m;

public:

    Binary_SemaPhore(bool flag = false) : flag(flag) { }


    void acquire()
    {
        std::unique_lock<std::mutex> lock(m);
        if (!flag)
        {
            cv.wait(lock);
        }

        flag = false;
    }

    void release()
    {
        std::lock_guard<std::mutex> lock(m);
        flag = true;
        cv.notify_one();
    }


};



Counting_SemaPhore sem(5);
//std::counting_semaphore<5> sem{5}; // Initialize counting_semaphore with 5 slots

void task(int id)
{
    std::cout << "Thread " << id << " is waiting to access the resource" << std::endl;

    sem.acquire();

    std::cout << "Thread " << id << " is accessing the resource" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " is finished accessing the resource" << std::endl;

    sem.release();
}

int start()
{
   
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
    {
        threads[i] = std::thread(task, i);
    }

    for (int i = 0; i < 10; i++)
    {
        threads[i].join();
    }
    return 0;
}
