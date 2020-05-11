#include <iostream>
using namespace std;

long long int dp[101] = { 0, 1, 1, 1, 2, 2 };

int main(void) {
	int n = 0;
	cin >> n;
	int* input = new int[n + 1]();
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 6; j <= input[i]; j++) {
			if (!dp[j]) {
				dp[j] = dp[j - 1] + dp[j - 5];
			}
		}
		cout << dp[input[i]] << endl;
	}
	return 0;
}