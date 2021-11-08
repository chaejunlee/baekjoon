#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001] = { 0 };
int wine[10001] = { 0 };

int algo(int n) {
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	return dp[n];
}

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1];
	dp[2] = max(wine[1] + wine[2], wine[2]);
	algo(n);
	/*cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << endl;
	}*/
	cout << dp[n];
	return 0;
}