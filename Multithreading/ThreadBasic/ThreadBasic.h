#pragma once

#include <iostream>
#include <thread>
#include <chrono>
//#include <algorithm>




using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;


//when we create multiple thread not sure which one will create first


// Ways to create Thread in c++

/*
1. Function Pointers
2. Lambda Function
3.Functors
4.Member functions
5. Static Member Functions
*/



ull oddSum = 0;
ull evenSum = 0;

void findOdd(ull start, ull end)
{
	for (ull i = start; i < end; i++)
	{
		if ((i & 1) == 1)
		{
			oddSum += i;
		}
	}
}

void findEven(ull start, ull end)
{
	for (ull i = start; i < end; i++)
	{
		if ((i & 1) == 0)
		{
			evenSum += i;
		}
	}
}

//1. Function Pointer

int start()
{
	ull start = 0, end = 19000000000;

	auto startTime = high_resolution_clock::now();
	std::thread t1(findOdd, start, end);
	std::thread t2(findEven, start, end);
	

	t1.join();
	t2.join();

	auto endTime = high_resolution_clock::now();

	auto ThreadExecutionTime = (duration_cast<microseconds>(endTime - startTime));

	startTime = high_resolution_clock::now();

	findOdd(start, end);
	findEven(start, end);

	endTime = high_resolution_clock::now();

	auto NormalExecutionTime = (duration_cast<microseconds>(endTime - startTime));

	cout << "odd Sum: " << oddSum << endl;
	cout << "Even Sum: " << evenSum << endl;

	cout << " Time Taken by Thread Execution: " << ThreadExecutionTime.count()/1000000 << endl;

	cout << "time taken by Normal execution: " << NormalExecutionTime.count()/1000000 << endl;



	return 0;
}



// Join -- we will wait to finish that thread after creating

//Detach -- We will create thread and Detach from main thread , if it is finish task before main thread finsih will return or else thread task terminate after main thread return

//joinable() -- checking thread is available to join before joing , because if you write multiople join call for same thread it will crash the program .
//  we need to check this before both join() and Detach() for confirmation



//Either join() or Detach() should be called on thread object, otherwise during thread objects destructor it will terminate the program
// Because inside destructor it checks if thread is joinable? if yes then it terminates the program.





