#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n = 0;
	int p[1001] = { 0 }, dp[1001] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dp[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++)
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}