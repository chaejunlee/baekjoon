#include <iostream>
using namespace std;

int max2(int a, int b) {
	return (a > b ? a : b);
}

int main(void) {
	int n = 0, m = 0;
	int** dp = new int*[2]();
	dp[0] = new int[100001]();
	dp[1] = new int[100001]();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++)
			cin >> dp[0][j];
		for (int j = 1; j <= m; j++)
			cin >> dp[1][j];
		dp[0][2] += dp[1][1];
		dp[1][2] += dp[0][1];
		for (int j = 3; j <= m; j++) {
			dp[0][j] += max2(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] += max2(dp[0][j - 2], dp[0][j - 1]);
		}
		cout << max2(dp[0][m], dp[1][m]) << endl;
	}
}