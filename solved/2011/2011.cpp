#include <iostream>
#include <string>
using namespace std;

long long dp[6000] = { 0 };

int main(void) {
	string str;
	cin >> str;
	int n = str.length();
	if ((str[0] - '0')) {
		dp[0] = 1;
		//dp[1] = 1;
	}
	else {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (str[i] > '0')
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		if (i == 1) continue;
		int x = (str[i] - '0') + 10 * (str[i - 1] - '0');
		if (10 <= x && x <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		if ((str[i] == '0') && (str[i + 1] == '0')) {
			cout << 0;
			return 0;
		}
	}
	cout << dp[n - 1];
	return 0;
}