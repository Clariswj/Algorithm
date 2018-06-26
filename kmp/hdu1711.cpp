#include<iostream>

using namespace std;
int Next[10005];
int a[1000005], b[10005];

void getNext(int x)
{
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < x)
	{
		if (j == -1 || b[i] == b[j])
			Next[++i] = ++j;
		else j = Next[j];
	}
}

int kmp(int x,int y)
{
	int i = 0, j = 0;
	while (i < x)
	{
		if (j == -1 || a[i] == b[j])
			i++, j++;
		else j = Next[j];
		if (j == y) return i - j + 1;
	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		getNext(n);
		cout << kmp(m, n)<< endl;
	}
}