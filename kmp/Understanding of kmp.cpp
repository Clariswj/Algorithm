/*
关于kmp中最重要的就是next数组的建立，一般next数组的建立有两种，一种是
next[0]=0，一种是-1开始，两种其实算出的next数组每个值差1，思维没差，因
为字符串是从0开始的，所以我就从-1开始。
下面给出例子：
首先是模板串……ababcab(c)aab……
      模式串    ababcab(a)bab    
	  注意到在括号处出现不匹配
	  按照暴力做法就是把模式串向后移一位挨个比较，但显然这样是浪费了。
	  因为下一个b显然是和模板串的第一个不匹配的，这时我们肯定想直接移成
	  ……ababcab(c)aab……
	           ab(a)bcab(a)bab
	  这样在不匹配字符c前面的的ab就能配对成功，这样才有可能继续匹配下去
	  这时我们发现这不就是寻找模式串中的前缀和后缀相同的部分吗
	  就如ababcab(a)bab我们发现ab前缀与后缀相同（从(a)之前的字符串看）
	  故next[7]=2，模式串向右移动的位置就是失配字符所在位置减去适配字符
	  对应的next值即j-next[j]，这样就可以通过移动j而不移动i而使时间复杂度达到o(m+n);
而next数组的求解：
      ababcababcb(从-1开始)
	   ababcababcb
	  令next[0]=-1,易知next[1]=0（即不存在前缀与后缀相同的部分），
	  每次都从第二个字符开始比较，因为如果从第一个开始比较就等于把整个字符串全选了
还有一个递推式：
      next[j]==k&&mo[j]==mo[k]
	  则next[j+1]=k+1；
*/

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
		}//模式串aba 模板串abababa 输出3
		//如果在这里将j清0的话 上面的输入将输入2
		//即一个可以能从aba中b接着，一个只能从abab……中的第二个b接着找
	}
	return ans;
}


int main()
{
	cin >> mo >> str;
	Next[0] = -1;
	buildNext();
	cout << kmp() << endl;
	return 0;
}