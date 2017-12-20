#include <string>
#include <iostream>
#include <vector>


using namespace std;
class IpAddr
{
public:
	IpAddr(string ip, int range)
	{
		IpAddress = CheckIp(ip);
		this->range = range;
	}
	void GetIpRange();
private:
	bool String2Int(const std::string& str, int& result);
	vector<int> CheckIp(string ip);
	vector<int> IpAddress;
	int range;
};
bool IpAddr::String2Int(const std::string& str, int& result) {
	std::string::const_iterator i = str.begin();

	if (i == str.end())
		return false;

	bool negative = false;

	if (*i == '-')
	{
		negative = true;
		++i;

		if (i == str.end())
			return false;
	}

	result = 0;

	for (; i != str.end(); ++i)
	{
		if (*i < '0' || *i > '9')
			return false;

		result *= 10;
		result += *i - '0';
	}

	if (negative)
	{
		result = -result;
	}

	return true;
}
vector<int> IpAddr::CheckIp(string s)
{
	vector<string> parts = vector<string>();
	IpAddress = vector<int>();
	string temp;
	int a = 0;
	try
	{
		while (s.find_first_of('.') != string::npos)
		{

			temp = s.substr(0, s.find_first_of("."));
			if (temp.length() > 3)
			{
				throw string( "Too many characters in a part");

			}
			if (!this->String2Int(temp, a))
			{
				throw string("Only digits and dots allowed");

			}
			parts.push_back(temp);
			s = s.substr(s.find_first_of(".") + 1);
		}
		parts.push_back(s);
		int result = 0;
		if (parts.size() != 4) {
			throw string("Incorrect parts count.");

		}
		for (int i = 0; i < parts.size(); i++)
		{
			String2Int(parts[i], a);
			if (a > 255)
			{
				throw string( "Too big a value of a part");

			}
			IpAddress.push_back(a);


		}
	}
	catch (...)
	{
		throw;
	}
	return IpAddress;
}
void IpAddr::GetIpRange()
{
	try {
		if((range & (range - 1)) != 0)
		{
			throw string("invalid range");
		}
		if ((IpAddress[3] + range) > 256)
			throw string("To big range value.");
		for (int i = 0; i < range; i++)
		{
			for (int j = 0; j < IpAddress.size() - 1; j++)
			{
				cout << IpAddress[j] << ".";
			}
			cout << (IpAddress[3] + i)<<endl;
		}
	}
	catch (...)
	{
		throw;
	}
}
int main(void) {
	try
	{
		IpAddr ip("192.168.21.4", 16);
		ip.GetIpRange();
	}
	catch (string &exp)
	{
		cout << "Exeption: " << exp << endl;
	}
	return 0;
}