#pragma onceN
#include <iostream>
#include <thread>

using namespace std;



//1.Function pointers 

//void fun(int x)
//{
//
//	while (x-- > 0)
//	{
//		cout << "Numbers: " << x << endl;
//	}
//}
//
//int start()
//{
//	std::thread t1(fun, 10);
//  t1.join();
//	return 0;
//}





//2. Lambda Fn

//int start()
//{
//
//
//	
//	/*auto fun = [](int x) {
//		while (x-- >0) { cout << "Numbers: " << x << endl; }
//		};
//	
//	std::thread t1(fun, 10);*/
//
//
//	std::thread t1( [](int x) 
//	{
//	while (x-- > 0) 
//	{ 
//		cout << "numbers: " << x << endl;
//	} 
//	} , 10);
//	t1.join();
//	return 0;
//}






////3. Functors (Function object)
//
//
//class Base
//{
//public:
//	void operator()(int x)
//	{
//		while (x-- > 0)
//		{
//			cout << "numbers: " << x << endl;
//		}
//	}
//};
//
//
//int start()
//{
//   
//	std::thread t1(Base(), 10);
//	t1.join();
//	return 0;
//}




//4.Non static Member Fn

//class Base
//{
//public:
//	void Run(int x)
//	{
//		while (x-- > 0)
//		{
//			cout << "numbers: " << x << endl;
//		}
//	}
//};
//
//
//int start()
//{
//	Base b;
//	std::thread t1(&Base::Run, &b, 10);
//	t1.join();
//	return 0;
//
//}



//5. static Member Fn

class Base
{
public:
	static void Run(int x)
	{
		while (x-- > 0)
		{
			cout << "numbers: " << x << endl;
		}
	}
};


int start()
{
	Base b;
	std::thread t1(&Base::Run, 10);
	t1.join();
	return 0;

}