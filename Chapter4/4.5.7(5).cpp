#include <iostream>
#include <math.h>
#include <string>

std::string ForDPatternNLeng(std::string pattern, std::string sentence)
{
	std::string result;
	int k = 0;
	for (int i = 0; i < pattern.length(); i++)
		for (int j = k; j < sentence.length(); j++)
			if (pattern.substr(i, 1) == "D")
				if ( ((sentence[j] - pattern[i]) <= -11) && sentence[j] - pattern[i] >= -20)
				{
					result += sentence.substr(j, 1);
					k = j + 1;
					j = sentence.length();
				}
	return result;
}

std::string ForAPatternNLeng(std::string pattern, std::string sentence)
{
	std::string result;
	for (int j = 0; j < sentence.length(); j++)
		for (int i = 0; i < pattern.length(); i++)
			if (result.length() == pattern.length())
				return result;
			else
			{
				if (sentence.substr(j, sentence.length()).substr(i, 1).compare("A") >= 0 && sentence.substr(j, sentence.length()).substr(i, 1) != " ")
					result += sentence.substr(j, sentence.length())[i];
				else
				{
					result = "";
					break;
				}
			}
	return result;
}

std::string ForQMPatternNLeng(std::string pattern, std::string sentence, std::string part)
{
	int n = sentence.find(part) + part.length();
	return sentence.substr(n, pattern.length());
}

std::string ForLCLPatternNLeng(std::string pattern, std::string sentence)
	std::string result;
	int k = 0;
	for (int i = 0; i < pattern.length(); i++)
		for (int j = k; j < sentence.length(); j++)
			if (sentence[j] == pattern[i] || abs(sentence[j] - pattern[i]) == 32)
			{
				result += sentence[j];
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

std::string FindAlg(std::string pattern, std::string sentence, std::string part)
{
	if(pattern.substr(0, 1)=="A")
		return ForAPatternNLeng(pattern, sentence);
	if (pattern.substr(0, 1) == "D")
		return ForDPatternNLeng(pattern, sentence);
	if (pattern.substr(0, 1) == "?")
		return ForQMPatternNLeng(pattern, sentence, part);
	else
		return ForLCLPatternNLeng(pattern, sentence);
}
int main()
{
	std::string pattern, sentence, result = "", part;
	std::cout << "Input pattern please" << std::endl;
	getline(std::cin, pattern);
	std::cout << "Input sentence please" << std::endl;
	getline(std::cin, sentence);
	int k = 0;
	int i = 0;
	std::cout << "The parts of sentence that matching your pattern is:" << std::endl;
	for (int j = 0; j < sentence.length() - pattern.length() + 1; j++)
	{
		do
		{
			part = pattern.substr(k, i - k + 1);
			i++;
		} while (pattern[i] == pattern[k]);
		k = i;
		if (FindAlg(part, sentence.substr(j, pattern.length()), result).length() < part.length())
		{

			result = "";
			i = 0;
			k = 0;
		}
		else
		{
			result += FindAlg(part, sentence.substr(j, pattern.length()), result);
			if (result.length() == pattern.length())
			{
				if (result == sentence.substr(j, pattern.length()))
					std::cout << result << std::endl;
				result = "";
				i = 0;
				k = 0;
			}
			else
				j--;
		}
	}
	return 0;
}
