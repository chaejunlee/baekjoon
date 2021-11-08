#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	string s[11];
	long long alphabet[26] = {0};
	
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			int pos = s[i][j] - 'A';
			alphabet[pos] -= (long long) pow(10.0, (double) (s[i].size() - 1 - j));
		}
	}
	
	sort(alphabet, alphabet + 26);
	
	long long res = 0;
	for (int i = 0; i < 10; i++) {
		//cout << alphabet[i] << "\n";
		res += alphabet[i] * (i - 9);
	}
	cout << res << "\n";
	
	return 0;
}