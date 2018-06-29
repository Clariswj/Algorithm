#include<iostream>
#include<vector>

using namespace std;
const int maxn = 1e5;
int arr[maxn];
vector<int> dk;

void insertionSort(int arr[], int n, int dk)
{
	for (int i = dk; i < n; i++){
		int tmp = arr[i];
		int j = i - dk;
		while (j >= 0 && arr[j]>tmp){
			arr[j + dk] = arr[j];
			j -= dk;
		}
		arr[j + dk] = tmp;
	}
}

void shellSort(int arr[], int n)//生成{1，4，13，40，121、、、、}
{
	for (int i = 1;;){
		if (i > n) break;
		dk.push_back(i);
		i = 3 * i + 1;//k(n+1)=3*k(n)+1时时间复杂度较低，基本维持在o(N^1.25)
	}
	for (int i = dk.size() - 1; i >= 0; i--){
		insertionSort(arr, n, dk[i]);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	shellSort(arr, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
}