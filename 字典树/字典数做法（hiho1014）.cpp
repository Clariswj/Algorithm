#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

char s[11];
int n,m;
bool p;

struct node
{
    int count;
    node * next[26];
}*root;

node * build()
{
    node * k=new(node);
    k->count=0;
    memset(k->next,0,sizeof(k->next));
    return k;
}

void insert()
{
    node * r=root;
    char * word=s;
     while(*word)
    {
        int id=*word-'a';
        if(r->next[id]==NULL) r->next[id]=build();
        r=r->next[id];
        r->count++;
        word++;
    }
}

int search()
{
    node * r=root;
    char * word=s;
    while(*word)
    {
        int id=*word-'a';
        r=r->next[id];
        if(r==NULL) return 0;
        word++;
    }
    return r->count;
}

void Del(Trie *p)
{
	for (int i = 0; i<26; i++)
	{
		if (p->next[i] != NULL)
			Del(p->next[i]);
	}
	delete(p);
}

int main()
{
    root=build();
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
            cin>>s;
            insert();
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        printf("%d\n",search());
    }
    Del(root);
}
