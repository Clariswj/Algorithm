#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 3e5;
char s[maxn];
char s_new[maxn];
int r[maxn];

void Init()
{
	s_new[0] = '$';
	s_new[1] = '#';
	int ls = strlen(s);
	for (int i = 0; i < ls; i++){
		s_new[2 * i + 2] = s[i];
		s_new[2 * i + 3] = '#';
	}
	s_new[2 * ls + 2] = '\0';
}

void manacher()
{
	int pos = 0, mx = 0;
	int ls_new = strlen(s_new);
	for (int i = 0; i < ls_new; i++){
		if (i < mx) r[i] = min(r[2 * pos - i], mx - i);
		else r[i] = 1;
		while (s_new[i - r[i]] == s_new[i + r[i]]) r[i]++;
		if (i + r[i]>mx){
			mx = i + r[i];
			pos = i;//pos为已经配对的离结尾最远的回文串的中心位置
		}
	}
}

int main()
{
	while (~(scanf("%s", s)))
	{
		Init();
		manacher();
		int ans = 0;
		int ls_new = strlen(s_new);
		for (int i = 0; i < ls_new; i++){
			ans = max(r[i], ans);
		}
		printf("%d\n", ans - 1);
	}
}
