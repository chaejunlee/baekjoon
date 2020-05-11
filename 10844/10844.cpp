#include <iostream>
using namespace std;

long long int dp[101][10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int main(void) {
	long long int n = 0, result = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i <= 9; i++)
		result += dp[n - 1][i];
	result %= 1000000000;
	cout << result;
}