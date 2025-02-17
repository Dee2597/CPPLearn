#pragma once

#include<iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char* data;
	unsigned int  len;

public:
	String() : data(nullptr), len(0) {}

	~String()
	{
		delete[] data;
	}

	String(const char* ch)
	{
		len = strlen(ch);
		data = new char[len + 1];
		strcpy_s(data, len + 1, ch); // Use strcpy_s for 


		/*char* strcpy(char* strDest, const char* strSrc)
		{
			assert(strDest != NULL && strSrc != NULL);
			char* temp = strDest;
			while (*strDest++ = *strSrc++); // or while((*strDest++=*strSrc++) != '\0');
			return temp;
		}*/
	}

	//f you do not explicitly define a copy constructor in your class, the compiler will generate a default copy constructor for you. The default copy constructor performs a shallow copy. 
	//String(const String& rhs) = default;
	// data = rhs.data shallow copy
	

	//copy constructor
	String(const String& rhs)
	{
		len = rhs.len;
		data = new char[len+1];
		if (rhs.data != nullptr)
		{
			strcpy_s(data, len + 1, rhs.data);
		}
		else
		{
			data = nullptr;
		}
		
	}


	//copy assignment
	String& operator=(const String& rhs)
	{

		if (this != &rhs)
		{
			delete[] data;
			len = rhs.len;
			data = new char[len + 1];
			strcpy_s(data, len + 1, rhs.data);
		}
		
		return *this;
	}

	String(String&& rhs) noexcept
	{

		/*In the move constructor, strcpy_s is not required because the move constructor transfers ownership of the resource(the dynamically allocated memory) from the source object(rhs) to the new object.
	    This means that the new object will directly take over the pointer to the data, 
	    and the source object will be left in a valid but unspecified state(typically with its pointer set to nullptr).*/

		data = rhs.data;
		len = rhs.len;
		rhs.len = 0;
		rhs.data = nullptr;
	}


	String& operator=(String&& rhs) noexcept
	{
		if (this != &rhs)
		{
			delete[] data;
			data = rhs.data;
			len = rhs.len;
			rhs.len = 0;
			rhs.data = nullptr;
		}
		return *this;
	}


	int length() const
	{
		
		return strlen(data);
	}

	friend istream& operator>>(istream& in,  String& str);

	friend ostream& operator <<(ostream& out, const String& str);



};

ostream& operator<<(ostream& out, const String& str)
{
	out << str.data;

	return out;
}


istream& operator>>(istream &in, String& str)
{
	char buffer[1000];
	in >> buffer;
	str.len = strlen(buffer);
	delete[] str.data;
	str.data = new char[str.len + 1];
	strcpy_s(str.data, str.len + 1, buffer);
	return in;

}




int start()
{
	String str1;  //defaut constructor
	String str2 = "hello"; //Parameterized ctor
	String str3 = str2;   //Copy Constructor

	cin >> str1;
	cout << str1 << endl;

	str3 = str1;  // copy asignment operator


	String str5 = std::move(str3);  //Move Constructor operator

	str2 = std::move(str5); //Move assignment operator


	int len = str2.length();

	cout << str2<<endl;
	
	return 0;


}