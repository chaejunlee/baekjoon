#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int mid(int a, int b, int c) {
	return (a < b ? (c < a ? a : (b < c ? b : c)) : (c < b ? b : (a < c ? a : c)));
}

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int arr[], int left, int right) {
	Swap(arr[left], arr[(rand() % (right - left + 1)) + left]);
	int pivot = arr[left];
	int low = left + 1, high = right;
	while (low <= high) {
		while (low <= right && arr[low] <= pivot)
			low++;
		while (high >= (left + 1) && arr[high] >= pivot)
			high--;
		if (low <= high)
			Swap(arr[low], arr[high]);
	}
	Swap(arr[left], arr[high]);
	return high;
}

int QuickSelect(int arr[], int left, int right, int select) {
	if (select >= 0 && select <= (right))
	{
		int pivot = Partition(arr, left, right);

		if (pivot == select)
			return arr[pivot]; 
		else if (pivot > select)
			return QuickSelect(arr, left, pivot - 1, select);
		else
			return QuickSelect(arr, pivot + 1, right, select);
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, index;
	cin >> n;
	cin >> index;
	srand(n + index);

	int* arr = new int[n]();

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << QuickSelect(arr, 0, n - 1, index - 1);
	return 0;
}