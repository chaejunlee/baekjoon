#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int arr[9];

// n: index of what to choose
// k: number of chosen elements
void solve(int n, int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (n >= v.size()) return;
	
	arr[k] = v[n];
	// choose n and on with n
	solve(n, k + 1);
	// choose n and to the next
	// solve(n + 1, k + 1); -> 이거 왜 안 쓰임? -> 중복이 맞네
	// not choose n
	solve(n + 1, k);
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		auto it = find(v.begin(), v.end(), temp);
		if (it == v.end()) v.push_back(temp);
	}
	sort(v.begin(), v.end());
	
	solve(0, 0);
	
	return 0;
}
