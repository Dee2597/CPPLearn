#pragma once
#include <iostream>
#include <string>
#include <regex>

/*
The Chain of Responsibility design pattern is a behavioral pattern that allows multiple objects to handle a request in a sequential manner. Each object in the chain has the option to handle the request or pass it on to the next object in the chain.

Here's a breakdown of the Chain of Responsibility pattern:

- Handler: An interface or abstract class that defines the handling behavior. It typically includes a method for handling requests and a reference to the next handler in the chain.
- Concrete Handler: A concrete implementation of the Handler interface. It handles requests and may pass them on to the next handler in the chain.
- Client: The object that initiates the request and passes it to the first handler in the chain.


*/


using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual StringValidator* setNext(StringValidator* nextValidator) = 0;
	virtual std::string validate(std::string) = 0;

};


class BaseValidator: public StringValidator
{
protected:
	StringValidator* next = nullptr;
public:
	virtual ~BaseValidator() { delete next;  }

	StringValidator* setNext(StringValidator* nextValidator) override
	{
		next = nextValidator;
		return nextValidator;
	}

	std::string validate(std::string testString)override
	{
		if (this->next)
		{
			return this->next->validate(testString);
		}

		return "SUCCESS";
	}
};


class NotEmptyValidator : public BaseValidator
{
public:
	NotEmptyValidator(){}

	std::string validate(std::string testString)
	{
		puts("checking if Empty");

		if (testString.empty())
		{
			return "Please enter some string";
		}

		return BaseValidator::validate(testString);

	}
};

class LengthValidator : public BaseValidator
{
	int minLength;
public:
	LengthValidator(int minLength) : minLength(minLength) {};

	std::string validate(std::string testString)override
	{
		puts("checking string Length....");
		if (testString.length() < minLength)
		{
			return "Please enter value longer than" + std::to_string(minLength);
		}

		return BaseValidator::validate(testString);
	}
};

class RegexValidator: public BaseValidator
{
	std::string patternName;
	std::string regexString;

public:
	RegexValidator(std::string patternName, std::string regexString) : patternName(patternName), regexString(regexString){}

	std::string validate(std::string testString)
	{
		puts("checking regex match....");

		if (!std::regex_match(testString, std::regex(regexString)))
		{
			return "The entered value doesn't match with proper format for a" + patternName;
		}

		return BaseValidator::validate(testString);
	}
};


bool is_available_in_array(std::vector<string>&data, std::string testString)
{
	return std::find(data.begin(), data.end(), testString) != data.end();
}

class HistroyValidator : public BaseValidator
{

	std::vector<string> histroyDatabase;

public:
	HistroyValidator(std::vector<string> histroyDatabase): histroyDatabase(histroyDatabase){}

	std::string validate(std::string testString)
	{
		puts("checking Histroy data....");

		if (!is_available_in_array(histroyDatabase, testString))
		{
			return "checking if string not used before......";
		}

		return BaseValidator::validate(testString);
	}

};


int start()
{

	std::vector<std::string> oldPasswords = { "abc123", "123456", "hello" };

	BaseValidator* emailValidator = new BaseValidator;

	emailValidator
		->setNext(new NotEmptyValidator)
		->setNext(new RegexValidator("email address", "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

	std::cout << "Checking Emails ---------------\n";
	std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
	std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
	std::cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n\n";

	delete emailValidator;
}




// Example 2:


class TicketHandler
{
public:
	virtual std::string Validate(std::string) = 0;
};



class JuniorTicketHandler : public TicketHandler
{
	TicketHandler* next1{};
public:
	JuniorTicketHandler(TicketHandler* next = nullptr) 
	{
		next1 = next;
	}

	std::string Validate(std::string ticket)
	{
		puts("Checking ticket validation......");

		if (ticket == "simple")
		{
			return "Ticket resolved by Junior Ticket Handler";
		}

		return next1->Validate(ticket);
	}
};


class SeniorTicketHandler : public TicketHandler
{
	TicketHandler* next2{};
public:
	SeniorTicketHandler(TicketHandler* next = nullptr)
	{
		next2 = next;
	}

	std::string Validate(std::string ticket)
	{
		puts("Checking ticket validation......");

		if (ticket == "medium")
		{
			return "Ticket resolved by Senior Ticket Handler";
		}

		return next2->Validate(ticket);
	}
};

class ManagerialTicketHandler : public TicketHandler
{
public:
	ManagerialTicketHandler()
	{
	}

	std::string Validate(std::string ticket)
	{
		puts("Checking ticket validation......");

		if (ticket == "Hard")
		{
			return "Ticket resolved by Managerial Ticket Handler";
		}
		else
		{
			return "Ticket severity is not proper";
		}
	}
};


int start1()
{
	ManagerialTicketHandler manager;
	SeniorTicketHandler senior(&manager);
	JuniorTicketHandler junior(&senior);
	TicketHandler* handel = &junior;

	std::cout << handel->Validate("hardd") << std::endl;
	
	
}