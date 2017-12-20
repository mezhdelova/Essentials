#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator
{
public:
	MinLengthValidator(int min) : StringValidator() { minlength = min; }
	bool isValid(std::string input);
private:
	int minlength;
};

bool MinLengthValidator::isValid(std::string input)
{
	return input.length() >= minlength;
}

class MaxLengthValidator : public StringValidator
{
public:
	MaxLengthValidator(int max) : StringValidator() { maxlength = max; }
	bool isValid(std::string input);
private:
	int maxlength;
};

bool MaxLengthValidator::isValid(std::string input)
{
	return input.length() <= maxlength;
}

class PatternValidator : public StringValidator
{
public:
	PatternValidator(std::string pattern) : StringValidator() { this->pattern = pattern; }
	bool isValid(std::string input);
private:
	std::string pattern;
	std::string ForDPatternNLeng(std::string pattern, std::string input);
	std::string ForAPatternNLeng(std::string pattern, std::string input);
	std::string ForLCLPatternNLeng(std::string pattern, std::string input);
	std::string ForQMPatternNLeng(std::string pattern, std::string input, std::string part);
	std::string FindAlg(std::string pattern, std::string input, std::string part);
};

std::string PatternValidator::ForDPatternNLeng(std::string patt, std::string input)//find std::string DD...D pattern
{
	std::string result = "";
	int k = 0;
	for (int i = 0; i < pattern.length(); i++)
		for (int j = k; j < input.length(); j++)
			if (pattern.substr(i, 1) == "D")
				if (((input[j] - pattern[i]) <= -11) && input[j] - pattern[i] >= -20)
				{
					result += input.substr(j, 1);
					k = j + 1;
					j = input.length();
				}
	return result;
}

std::string PatternValidator::ForAPatternNLeng(std::string patt, std::string input)//findstd::string matching AA...A pattern
{
	std::string result;
	for (int j = 0; j < input.length(); j++)
		for (int i = 0; i < pattern.length(); i++)
			if (result.length() == pattern.length())
				return result;
			else
			{
				if (input.substr(j, input.length()).substr(i, 1).compare("A") >= 0 && input.substr(j, input.length()).substr(i, 1) != " ")
					result += input.substr(j, input.length())[i];
				else
				{
					result = "";
					break;
				}
			}
	return result;
}

std::string PatternValidator::ForQMPatternNLeng(std::string patt, std::string input, std::string part)//findstd::string matching ??...? pattern
{
	int n = input.find(part) + part.length();
	return  input.substr(n, pattern.length());
}

std::string PatternValidator::ForLCLPatternNLeng(std::string patt, std::string input)//findstd::string matching lower-case leters pattern
{
	std::string result = "";
	int k = 0;
	for (int i = 0; i < pattern.length(); i++)
		for (int j = k; j < input.length(); j++)
			if (input[j] == pattern[i] || abs(input[j] - pattern[i]) == 32)
			{
				result += input[j];
				i++;
				if (result.length() == pattern.length())
					return result;
			}
			else
			{
				i = 0;
				result = "";
			}
	return result;
}

std::string PatternValidator::FindAlg(std::string patt, std::string input, std::string part)
{
	if (pattern.substr(0, 1) == "A")
		return ForAPatternNLeng(pattern, input);
	if (pattern.substr(0, 1) == "D")
		return ForDPatternNLeng(pattern, input);
	if (pattern.substr(0, 1) == "?")
		return ForQMPatternNLeng(pattern, input, part);
	else
		return ForLCLPatternNLeng(pattern, input);
}

bool PatternValidator::isValid(std::string input)
{
	int i = 0, k = 0;
	string part, result = "";
	for (int j = 0; j < input.length() - pattern.length() + 1; j++)
	{
		do
		{
			part = pattern.substr(k, i - k + 1);
			i++;
		} while (pattern[i] == pattern[k]);
		k = i;
		if (FindAlg(part, input.substr(j, pattern.length()), result).length() < part.length())
		{
			result = "";
			i = 0;
			k = 0;
		}
		else
		{
			result += FindAlg(part, input.substr(j, pattern.length()), result);
			if (result.length() == pattern.length())
			{
				if (result == input.substr(j, pattern.length()))
					return true;
				result = "";
				i = 0;
				k = 0;
			}
			else
				j--;
		}
	}
	return false;
}


void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid") << endl;
}
int main() {
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("DD");
	printValid(digit, "there are 22 types of inputs in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;
	return 0;
}
