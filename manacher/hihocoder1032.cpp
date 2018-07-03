#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 1e8;
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

int manacher()
{
	int pos = 0, mx = 0, max_r = 0;
	int ls_new = strlen(s_new);
	for (int i = 0; i < ls_new; i++){
		if (i < mx) r[i] = min(r[2 * pos - i], mx - i);
		else r[i] = 1;
		while (s_new[i - r[i]] == s_new[i + r[i]]) r[i]++;
		if (i + r[i]>mx){
			mx = i + r[i];
			pos = i;
		}
		if (r[i] - 1>max_r){
			max_r = r[i] - 1;
		}
	}
	return max_r;
}

int main()
{
	int n;
	cin >> n;
	while (n--){
		scanf("%s", s);
		Init();
		printf("%d\n", manacher());
	}
}