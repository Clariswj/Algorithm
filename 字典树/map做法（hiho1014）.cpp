#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> m;

int main()
{
	int n;
	cin >> n;
	string str, r;
	while (n--)
	{
		cin >> str;
		for (int i = 1; i <= str.length(); i++)
		{
			r = str.substr(0, i);
			if (m.count(r))
				m[r]++;
			else m[r] = 1;
		}
	}
	int x;
	cin >> x;
	while (x--)
	{
		cin >> str;
		cout << m[str] << endl;
	}
}