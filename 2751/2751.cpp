#include <iostream>
#include <algorithm>
using namespace std;

int ary[1000001] = { 0 };
int temp[1000001] = { 0 };

void merge(int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		if (ary[i] < ary[j])
			temp[k] = ary[i++];
		else
			temp[k] = ary[j++];
		k++;
	}
	if (i > mid)
		for (; j <= high; j++)
			temp[k++] = ary[j];
	else
		for (; i <= mid; i++)
			temp[k++] = ary[i];
	for (int idx = low; idx <= high; idx++)
		ary[idx] = temp[idx];
}

void mergeSort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ary[i];
	mergeSort(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ary[i]);
	}
}