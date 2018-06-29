#include<iostream>

using namespace std;
const int maxn = 1e5;

void bubbleSort(int arr[], int n)
{
	bool flag = 1;
	for (int i = 0; flag; i++){
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--){
			if (arr[j] < arr[j - 1]){
				std::swap(arr[j], arr[j - 1]);
				flag = 1;
			}
		}
	}
}

int main()
{
	int n, arr[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
}