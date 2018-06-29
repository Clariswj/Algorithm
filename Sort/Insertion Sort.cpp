#include<iostream>

using namespace std;
const int maxn = 1e5;

void insertionSort(int arr[], int n)
{
	int temp, i, j;
	for (i = 1; i < n; i++){
		temp = arr[i];//待插入区域的首元素
		j = i - 1;
		while (j >= 0 && arr[j]>temp){//拿有序区域的元素与带插入区域挨个比较，比
			arr[j + 1] = arr[j];      //temp大的往后依次往后移一位
			j--;
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	int n, arr[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	insertionSort(arr, n);
	for (int i = 0; i < n; i++){
		if (i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
}