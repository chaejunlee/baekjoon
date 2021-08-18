#include <bits/stdc++.h>
using namespace std;

int liquid[100001];

int binSearch(int left, int right, int L) {
    //cout << left << " " << right << " " << L << "\n";
	if (left < right) {
		int mid = (left + right) / 2;
		if (liquid[mid] + L < 0) {
			int ret = binSearch(mid + 1, right, L);
			if (abs(liquid[mid] + L) > abs(ret + L)) {
			    return ret;
			}
		}
		else if (liquid[mid] + L > 0) {
			int ret = binSearch(left, mid - 1, L);
			if (abs(liquid[mid] + L) > abs(ret + L)) {
			    return ret;
			}
		}
		return liquid[mid];
	}
	else {
		return liquid[left];
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}
	int res1 = 0;
	int res2 = 0;
	int m = 2000000001;
	for (int i = 1; i < N; i++) {
		int val = binSearch(i, N - 1, liquid[i - 1]);
		if (m > abs(val + liquid[i - 1])) {
			m = abs(val + liquid[i - 1]);
			res1 = liquid[i - 1];
			res2 = val;
		}
	}
    cout << res1 << " " << res2 << "\n";

	return 0;
}
