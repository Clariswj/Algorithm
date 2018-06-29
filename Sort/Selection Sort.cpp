#include<iostream>

using namespace std;
const int maxn = 1e5;

void selectionSort(int arr[], int n)
{
	int i, j, minj;
	for (i = 0; i < n - 1; i++){
		minj = i;
		for (j = i; j < n; j++){
			if (arr[j] < arr[minj]) minj = j;
		}
		std::swap(arr[i], arr[minj]);
	}
}

int main()
{
	int n, arr[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	selectionSort(arr, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
}