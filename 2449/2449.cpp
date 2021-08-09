#include <bits/stdc++.h>
using namespace std;

int N, K;
int bulb[201];
int cache[201][201];

int solve(int left, int right) {
	if (left == right) return 0;
	
	int& ret = cache[left][right];
	if (ret != -1) return ret;
	ret = 4001;
	
	for (int i = left; i < right; i++) {
		int weight = 0;
		if (bulb[left] != bulb[i + 1]) weight = 1;
		ret = min(ret, solve(left, i) + solve(i + 1, right) + weight);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> bulb[i];
	
	memset(cache, -1, sizeof(cache));
	
	int ret = solve(1, N);
	cout << ret << "\n";
	
	return 0;
}