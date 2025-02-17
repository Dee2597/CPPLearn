#pragma once

#include <iostream>
#include <string>

using namespace std;

class Input
{
public:
	Input() {}

	void input()
	{
		char ch;
		string name;
		cout << "Enter character: " << endl;
		cin >> ch;
		cin.ignore();
		cout << "Enter string: " << endl;
		getline(cin, name);
		cout << "The entered char is: " << ch << "The string is: " << name << endl;
	}
};
