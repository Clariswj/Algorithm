#include<iostream>
#define setmaxn 100000000

using namespace std;

const int maxn = 1e5;
int l[maxn / 2 + 5], r[maxn / 2 + 5];

int partition(int a[], int p, int r)
{
	int i, j;
	int x = a[r];
	i = p - 1;
	for (j = p; j < r; j++){
		if (a[j] <= x){
			i++;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[r]);
	return i + 1;
}

void quickSort(int a[], int p, int r)//最差的情况可能会时间复杂度达O(n^2)
{
	int q;
	if (p < r){
		q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int main()
{
	int n, a[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}