#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int pyramid[501][501] = { { 0 } };
int dp[501][501] = { { 0 } };

int max2(int a, int b) {
	return (a > b) ? a : b;
}

void algo(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + pyramid[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + pyramid[i][j];
			else
				dp[i][j] = max2(dp[i - 1][j - 1], dp[i - 1][j]) + pyramid[i][j];
		}
	}
}

int main(void) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf(" %d", &(pyramid[i][j]));
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" %d", pyramid[i][j]);
		}
		printf("\n");
	}*/

	algo(n);
	sort(&(dp[n][1]), &(dp[n][1]) + n);
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" %d", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", dp[n][n]);
	return 0;
}