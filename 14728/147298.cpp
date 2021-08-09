#include <bits/stdc++.h>
using namespace std;

int N, T;
int K[101], S[101];
int cache[101][10001];

int solve(int n, int t) {
	if (t < 0) return -1000001;
	if (n == 0) return 0;
	
	int& ret = cache[n][t];
	if (ret != -1) return ret;
	ret = 0;
	
	ret = max(solve(n - 1, t - K[n]) + S[n], solve(n - 1, t));
	
	//cout << n << " " << t << " " << ret << "\n";
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> K[i] >> S[i];
	}
	memset(cache, -1, sizeof(cache));
	
	cout << solve(N, T) << "\n";
	
	return 0;
}