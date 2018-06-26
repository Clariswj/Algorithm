#include<iostream>
#include<cstring>

using namespace std;

int Next[10005];
char str[1000005], mo[10005];

void buildNext()
{
	int j = 0;
	int lm = strlen(mo);
	int t = -1;
	while (j < lm)
	{
		if (t == -1 || mo[j] == mo[t])
			Next[++j] = ++t;
		else t = Next[t];
	}
}

int kmp()
{
	int ls = strlen(str), lm = strlen(mo);
	int i = 0, j = 0;
	int ans = 0;
	while (i < ls)
	{
		if (j == -1 || str[i] == mo[j])	i++, j++;
		else j = Next[j];
		if (j == lm) {
			ans++;
		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> mo >> str;
		Next[0] = -1;
		buildNext();
		cout << kmp() << endl;
	}
	return 0;
}