#include "stdafx.h"
#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator{
public:
	bool isValid(std::string input);
	ExactValidator(std::string valid) {
		_stringvalidator = valid;
	};
private:
	std::string _stringvalidator;
};

bool ExactValidator::isValid(std::string input)
{
	return _stringvalidator == input;
}


class DummyValidator : public StringValidator {
public:
	virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input)
{
	return true;
}
using namespace std;
void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid("hello") ? "valid" : "invalid") << endl;
}
int main()
{
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	return 0;
}
