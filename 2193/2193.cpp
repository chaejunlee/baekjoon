#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long dp[91] = { 0 };

long long func(int n)
{
	if (n == 2)
		return 1;
	if (!dp[n])
	{
		func(n - 1);
		func(n - 2);
	}
	dp[n] = dp[n - 1] + dp[n - 2];
	return dp[n];
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	func(n);
	for (int i = 0; i < 91; i++)
		printf("%d %lld\n", i, dp[i]);
	printf("%lld", dp[n]);

	return 0;
}