#include <iostream>

using namespace std;

int rgb[1002][3] = { {0, 0, 0} };
int dp1[1002][3] = { {0, 0, 0} };
int dp[1002] = { 0 };

int min(int a, int b) {
	return (a > b) ? b : a;
}

int minRGB(int n) {
	for (int i = 1; i <= n; i++) {
		dp1[i][0] = min(dp1[i - 1][1], dp1[i - 1][2]) + rgb[i][0];
		dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][2]) + rgb[i][1];
		dp1[i][2] = min(dp1[i - 1][0], dp1[i - 1][1]) + rgb[i][2];
	}
	return min(min(dp1[n][0], dp1[n][1]), dp1[n][2]);
}

void minRGB1(int n, int prevColor) {
	if (n < 1) return;
	int prevcolor = -1;
	int color = 0;
	for (int k = 1; k <= n; k++) {
		int minValue = 1000001, minIndex = 0;
		for (int i = 0; i < 3; i++) {
			if (i != prevcolor) {
				for (int j = 0; j < 3; j++) {
					if (i != j) {
						if (minValue > rgb[k][i] + rgb[k + 1][j]) {
							minValue = rgb[k][i] + rgb[k + 1][j];
							color = i;
						}
					}
				}
			}
		}
		prevcolor = color;
		dp[k] = dp[k - 1] + rgb[k][color];
		cout << dp[k] << " " << color << " " << dp1[k][0] << " " << dp1[k][1] << " " << dp1[k][2] << endl;
	}
}


int main(void) {
	int count = 0, value = 0;
	cin >> count;
	for (int i = 1; i <= count; i++)
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	cout << "1. " << minRGB(count) << endl;
	minRGB1(count, -1);
	cout << dp[count] << endl;
	return 0;
}