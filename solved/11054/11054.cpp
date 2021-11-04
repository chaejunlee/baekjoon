#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0 };
int series[1001] = { 0 };

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> series[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (series[i] > series[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (series[i] < series[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	sort(dp, dp + n + 1);
	cout << dp[n];
	return 0;
}