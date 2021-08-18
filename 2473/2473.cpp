#include <bits/stdc++.h>
using namespace std;

long long liquid[5001];

long long binSearch(int left, int right, int L) {
    //cout << left << " " << right << " " << L << "\n";
	if (left < right) {
		int mid = (left + right) / 2;
		if (liquid[mid] + L < 0) {
			long long ret = binSearch(mid + 1, right, L);
			if (abs(liquid[mid] + L) > abs(ret + L)) {
			    return ret;
			}
		}
		else if (liquid[mid] + L > 0) {
			long long ret = binSearch(left, mid - 1, L);
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
	sort(liquid, liquid + N);
	int res1 = 0;
	int res2 = 0;
	int res3 = 0;
	long long m = 3000000001;
	for (int i = 1; i < N - 1; i++) {
	    for (int j = 0; j < i; j++) {
	        int L = liquid[i] + liquid[j];
    		long long val = binSearch(i + 1, N - 1, L);
    		long long comp = val + L;
    		if (m > abs(comp)) {
    			m = abs(comp);
    			res1 = liquid[j];
    			res2 = liquid[i];
    			res3 = val;
    		}
	    }
	}
    cout << res1 << " " << res2 << " " << res3 << "\n";

	return 0;
}
