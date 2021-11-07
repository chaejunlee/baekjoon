#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> rope;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		rope.push_back(temp);
	}
	sort(rope.begin(), rope.end());
	int M = 0;
	for (int i = 0; i < N; i++) {
		M = max(M, rope[i] * (N - i));
	}
	cout << M << "\n";
	
	return 0;
}