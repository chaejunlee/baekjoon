#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	int n = 0, d = 0;
	int arr[10001] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		arr[d]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}