/*
对于排序区的每个元素，统计小于它的元素个数，然后进行排序
*/

#include<iostream>

using namespace std;

const int maxn = 1e5;
int count[maxn], s[maxn];
//count在下面函数直接使用会报错，加::局域解析符即可，也可改count为Count

void comparisioncountingSort(int a[], int n)
{
	for (int i = 0; i < n; i++) ::count[i] = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] < a[j]) ::count[j]++;
			else ::count[i]++;
		}
	}
	for (int i = 0; i < n; i++){
		s[::count[i]] = a[i];
	}
}

int main()
{
	int n, arr[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	comparisioncountingSort(arr, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << s[i];
	}
	cout << endl;
}