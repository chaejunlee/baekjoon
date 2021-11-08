#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int> > applicant;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		applicant.clear();
		for (int i = 0; i < N; i++) {
			int resume, interview;
			cin >> resume >> interview;
			applicant.push_back({resume, interview});
		}
		sort(applicant.begin(), applicant.end());
		sort(applicant.begin(), applicant.end(), cmp);
		
		int before = N + 1;
		int ret = 0;
		
		for (auto a : applicant) {
			if (before > a.first) {
				before = a.first;
				ret++;
			}
			if (a.first == 1) break;
		}
		cout << ret << "\n";
	}
	
	return 0;
}