#include <iostream>
using namespace std;

int main(void) {
	int n = 0;
	int dp[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			dp[j] += dp[j - 1];
			dp[j] %= 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[i];
		// cout << dp[i] << " ";
	}

	cout << (sum % 10007);
}