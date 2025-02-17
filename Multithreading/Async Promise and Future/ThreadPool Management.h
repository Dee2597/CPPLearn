#pragma once


/*

Task scheduling and execution is a crucial aspect of concurrent programming. Here's an overview:

Task Scheduling
Task scheduling refers to the process of allocating tasks to threads or other execution units for execution. The goal of task scheduling is to optimize system performance, ensure fairness, and minimize overhead.

Task Execution
Task execution refers to the actual running of tasks on threads or other execution units. This involves managing the lifecycle of tasks, including creation, execution, and completion.

Key Concepts
1. Task queues: Data structures that hold tasks waiting to be executed.
2. Schedulers: Components responsible for allocating tasks to threads or other execution units.
3. Thread pools: Collections of threads that can be reused to execute tasks.
4. Task parallelism: The degree to which tasks can be executed concurrently.

Scheduling Algorithms
1. First-Come-First-Served (FCFS): Tasks are executed in the order they arrive.
2. Shortest Job First (SJF): Tasks with the shortest execution time are executed first.
3. Priority Scheduling: Tasks with higher priorities are executed before tasks with lower priorities.
4. Round-Robin (RR): Tasks are executed in a circular order, with each task receiving a fixed time slice.

Execution Models
1. Thread-per-task: Each task is executed by a dedicated thread.
2. Thread pool: A pool of threads is used to execute tasks.
3. Async/await: Tasks are executed asynchronously, with the await keyword used to suspend execution until the task completes.

Benefits
1. Improved responsiveness: Task scheduling and execution can improve system responsiveness by allowing tasks to be executed concurrently.
2. Increased throughput: By executing tasks in parallel, task scheduling and execution can increase system throughput.
3. Better resource utilization: Task scheduling and execution can help optimize resource utilization by allocating tasks to threads or other execution units efficiently.

*/


#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

// Task structure
struct Task {
    std::function<void()> func;
};

// Thread pool class
class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        // Create threads
        for (size_t i = 0; i < numThreads; ++i) {
            threads.emplace_back([this] {
                while (true) {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        // Wait for task or stop signal
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    // Execute task
                    task.func();
                }
                });
        }
    }

    // Add task to queue
    template <typename F>
    void enqueue(F&& func) {
        Task task;
        task.func = std::forward<F>(func);
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.push(std::move(task));
        }
        condition.notify_one();
    }

    // Stop thread pool
    void stopPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        // Wait for threads to finish
        for (std::thread& thread : threads) {
            thread.join();
        }
    }

private:
    std::vector<std::thread> threads;
    std::queue<Task> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

// Example task function
void exampleTask() {
    std::cout << "Task executed" << std::endl;
}

int main() {
    // Create thread pool with 4 threads
    ThreadPool pool(4);

    // Enqueue tasks
    for (int i = 0; i < 10; ++i) {
        pool.enqueue(exampleTask);
    }

    // Stop thread pool
    pool.stopPool();

    return 0;
}