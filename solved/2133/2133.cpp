#include <iostream>
#include <algorithm>
using namespace std;

int dp[31] = { 1, 0, 3 };
int main(void) {
	int n = 0;
	cin >> n;
	if (!(n % 2))
		for (int i = 4; i <= n; i += 2) {
			dp[i] = 3 * dp[i - 2];
			for (int j = 0; j <= i - 4; j += 2)
				dp[i] += 2 * dp[j];
		}
	cout << dp[n];
	return 0;
}