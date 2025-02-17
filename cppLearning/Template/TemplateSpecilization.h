#pragma once

//sometime we have to specilize template for particular data type

#include<iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>

T AddNum(vector<T>& arr)
{
	T sum = 0;
	for (auto& ele : arr)
	{
		sum += ele;
	}
	return sum;
}

template<>
string AddNum(vector<string>& arr)
{
	int sum = 0;
	for (auto& ele : arr)
	{
		for (auto& ch : ele)
		{
			sum += ch;
		}
	}

	return to_string(sum);
}


int start()
{
	vector<int>integers{ 1,2,3,4,5,6,7,8,9,10 };
	vector<double>doubles{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
	vector<string> strings{ "abc", "bcd", "cde" };

	cout<<"The integers sum is"<<AddNum(integers)<<endl;
	cout << "The double sum is" << AddNum(doubles) << endl;
	cout << "The string sum is" << AddNum(strings) << endl;
}