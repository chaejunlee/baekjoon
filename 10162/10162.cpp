#include <bits/stdc++.h>
using namespace std;

int button[3] = {300, 60, 10};
int res[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int i = 0; i < 3; i++) {
		res[i] = T / button[i];
		T %= button[i];
	}
	if (T == 0) {
		cout << res[0] << " " << res[1] << " " << res[2] << "\n";
	}
	else {
		cout << "-1\n";
	}
	
	
	return 0;
}