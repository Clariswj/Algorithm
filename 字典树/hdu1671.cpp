#include<iostream>
#include<cstring>
using namespace std;

char str[10005][10];

struct Trie
{
	int count;
	Trie *next[10];
}*root;

Trie *create()
{
	Trie *p=new Trie;
	p->count = 0;
	memset(p->next, 0, sizeof(p->next));
	return p;
}

void insert(char *str)
{
	Trie *r = root;
	while (*str)
	{
		int tmp = *str - '0';
		if (r->next[tmp] == NULL) r->next[tmp] = create();
		r = r->next[tmp];
		r->count++;
		str++;
	}
}

int search(char *str)
{
	Trie *r = root;
	while (*str)
	{
		int tmp = *str - '0';
		r = r->next[tmp];
		if (r == NULL) return 0;
		str++;
	}
	return r->count;
}

void Del(Trie *p)
{
	for (int i = 0; i<10; i++)
	{
		if (p->next[i] != NULL)
			Del(p->next[i]);
	}
	delete(p);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		root = create();
		int n;
		int flag = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			insert(str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (search(str[i])>1)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0) cout << "NO\n";
		else cout << "YES\n";
		Del(root);
	}
}