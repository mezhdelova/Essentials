#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
bool String2Int(const std::string& str, int& result)
{

	istringstream buffer(str);
	if (!(buffer >> result))
	{
		result = 0;
		return false;
	}
	return true;
}
int main(void) {
	string s;
	cout << "Input Ip Address which you want to check"<<endl;
	getline(cin, s);
	vector<string> parts = vector<string>();
	string temp;
	int a = 0;
	while (s.find_first_of('.') != string::npos)
	{

		temp = s.substr(0, s.find_first_of("."));
		if (temp.length() > 3)
		{
			cout << "Too many characters in a part" << endl;
			return 0;
		}
		if (!String2Int(temp, a))
		{
			cout << "Only digits and dots allowed"<<endl;
			return 0;
		}
		parts.push_back(temp);
		s = s.substr(s.find_first_of(".") + 1);
	}
	parts.push_back(s);
	int result = 0;
	if (parts.size() != 4) {
		cout << "Incorrect parts count."<<endl;
		return 0;
	}
	for (int i = 0; i < parts.size(); i++)
	{
		String2Int(parts[i], a);
		if (a > 255)
		{
			cout <<"To big a value of a part" << endl;
			return 0;
		}

	}
	cout << "Correct Ip"<<endl;
	return 0;
}
