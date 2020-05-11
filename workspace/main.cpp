#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[301] = { 0 };
int input[301] = { 0 };

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> input[i];
	dp[1] = input[1];
	dp[2] = max(input[1] + input[2], input[2]);
	dp[3] = max(input[1] + input[3], input[2] + input[3]);
	dp[4] = max(dp[2] + input[4], dp[1] + input[3] + input[4]);
	dp[5] = max(dp[3] + input[5], dp[2] + input[4] + input[5]);
	for (int i = 6; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + input[i - 1]) + input[i];
	}
	cout << dp[n];
	return 0;
}

/*
-2751
-11650
-11651
-10814
-10825
-10989
-11652
11004
10828
9012
10799
10845
10866
10808
10809
10820
2743
11655
10824
11656
1406
1158
1168
10430
2609
1934
1850
9613
11005
2745
1373
1212
2089
11576
1978
1929
6588
11653
10872
1676
2004
*/
