#include <iostream>
#include <string>
#include <vector>
using namespace std;
class IPAddress
{
    public:
    string ipadd;
    bool String2Int(const std::string& str, int& result);
    bool CheckIP(string s);
    void printip(string ipadd)
    {cout << "You've input this ip "<< ipadd <<endl;}
};
class Network
{ public:
    IPAddress ad1;
    IPAddress ad2;
    IPAddress ad3;
    Network(IPAddress ad1, IPAddress ad2, IPAddress ad3);
};
void printNetwork(Network n1, Network n2)
{
    cout<< "Network 1 "<<endl;
    cout<< n1.ad1.ipadd <<endl;
    cout<< n1.ad2.ipadd <<endl;
    cout<< n1.ad3.ipadd <<endl;
    cout<< "Network 2 "<<endl;
    cout<< n2.ad1.ipadd <<endl;
    cout<< n2.ad2.ipadd <<endl;
    cout<< n2.ad3.ipadd <<endl;
}
Network::Network(IPAddress ad1, IPAddress ad2, IPAddress ad3)
{
    this->ad1 = ad1;
    this->ad2 = ad2;
    this->ad3 = ad3;
}
bool IPAddress::String2Int(const std::string& str, int& result)
{
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
bool IPAddress::CheckIP(string s)
{
    vector<string> parts = vector<string>();
    string temp;
    int a = 0;
    while (s.find_first_of('.') != string::npos)
    {

        temp = s.substr(0, s.find_first_of("."));
        if (temp.length() > 3)
        {
            cout<< "Too many characters in a part ";
            return false;
        }
        if (!String2Int(temp, a))
        {
            cout<< "Only digits and dots allowed ";
            return false;
        }
        parts.push_back(temp);
        s = s.substr(s.find_first_of(".") + 1);
    }
    parts.push_back(s);
    int result = false;
    if(parts.size() != 4){
		cout<<"Incorrect parts count. ";
		return false;
	}
	for (int i = 0; i < parts.size(); i++)
    {
        String2Int(parts[i],a);
        if(a > 255 )
        {
            cout<<"Too big a value of a part! ";
            return false;
        }

    }
    cout<<"Correct IP ";
    return true;
}
int main(void) {
    cout<<"Provide 5 ip adsresses" <<endl;
    string a1, a2,a3,a4,a5;
    getline(cin,a1);
    getline(cin,a2);
    getline(cin,a3);
    getline(cin,a4);
    getline(cin,a5);
    IPAddress ad1, ad2, ad3, ad4, ad5;
    ad1.ipadd = a1;
    ad2.ipadd = a2;
    ad3.ipadd = a3;
    ad4.ipadd = a4;
    ad5.ipadd = a5;
    Network n1(ad1, ad2,ad3);
    Network n2(ad3, ad4,ad5);
    printNetwork(n1, n2);
	return 0;
}
