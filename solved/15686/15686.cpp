#include <bits/stdc++.h>
using namespace std;

int N, M;
struct place {
    int y,x;
};
vector<place> store;
vector<place> house;
place arr[14];

int solve(int k, int n) {
    if (n == M) {
        int ret = 0;
        for (auto h : house) {
            int sum = 250000;
            for (int i = 0; i < M; i++) {
                sum = min(sum, abs(h.y - arr[i].y) + abs(h.x - arr[i].x));
            }
            ret += sum;
        }/*
        for (int i = 0; i < M; i++) {
            cout << arr[i].y << " " << arr[i].x << "\n";
        }
        cout << ret << "\n";
        */
        return ret;
    }
    if (k == store.size()) return 250000;
    
    // k번째 매장 선택
    arr[n] = store[k];
    int ret = solve(k + 1, n + 1);
    // k번째 매장 선택하지 않음
    ret = min(ret, solve(k + 1, n));
    
    return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;
	for (int i = 0; i < N; i++) {
	    for (int j = 0; j < N; j++) {
	        int temp;
	        cin >> temp;
	        if (temp == 1) {
	            house.push_back({i, j});
	        }
	        if (temp == 2) {
	            store.push_back({i, j});
	        }
	    }
	}
	
	cout << solve(0, 0);
	
	
	return 0;
}
