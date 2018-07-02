#include<iostream>
#define setmaxn 100000000

using namespace std;

const int maxn = 1e5;
int l[maxn / 2 + 5], r[maxn / 2 + 5];

void merge(int a[],int left,int mid,int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) l[i] = a[i + left];
	for (int i = 0; i < n2; i++) r[i] = a[i + mid];//不足，额外占用了O(n)空间
	l[n1] = r[n2] = setmaxn;
	int i = 0, j = 0;
	for (int k = left; k < right; k++){
		if (l[i] <= r[j]){
			a[k] = l[i++];
		}
		else a[k] = r[j++];
	}
}

void mergeSort(int a[],int left,int right)
{
	if (left + 1 < right){//元素超过一个进行排序操作
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main()
{
	int n, a[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	mergeSort(a, 0, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}