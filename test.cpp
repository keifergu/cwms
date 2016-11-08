#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string*> res() {
	std::vector<string*> v;
	string s[] = {"s", "b"};
	cout<<s[0];
	v.push_back(s);
	cout<<v[0][0];
	return v;
}

int main(int argc, char const *argv[])
{
	std::vector<string*> v;
	cout<<"s";
	v = res();
	cout<<v[0][0]<<endl;
	return 0;
}