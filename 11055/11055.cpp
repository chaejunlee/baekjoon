#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct serie {
	int index;
	int sum;
} serie;

serie dp[1001] = { 0 };
int series[1001] = { 0 };

bool cmp(const serie& p1, const serie& p2) {
	if (p1.sum < p2.sum) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> series[i];
	for (int i = 1; i <= n; i++) {
		dp[i].index = 1;
		dp[i].sum = series[i];
		for (int j = 1; j < i; j++) {
			if (series[j] < series[i] && dp[j].index >= dp[i].index) {
				dp[i].index = dp[j].index + 1;
				if (dp[i].sum < dp[j].sum + series[i])
					dp[i].sum = dp[j].sum + series[i];
			}
		}
	}
	sort(dp, dp + n + 1, cmp);
	cout << dp[n].sum;
}
//
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int dp[1001] = { 0 };
//int series[1001] = { 0 };
//
//int main(void) {
//	int n = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> series[i];
//	for (int i = 1; i <= n; i++) {
//		dp[i] = series[i];
//		for (int j = 1; j < i; j++) {
//			if (series[j] < series[i] && dp[i] < dp[j] + series[i]) {
//				dp[i] = dp[j] + series[i];
//			}
//		}
//	}
//	sort(dp, dp + n + 1);
//	cout << dp[n];
//}