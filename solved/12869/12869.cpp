#include <bits/stdc++.h>

using namespace std;

int t = 0, N = 0, M = 0, K = 0;
int arr[4];
int cache[61][61][61];
int damage[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int solve(int hp1, int hp2, int hp3) {
    //cout << hp1 << " " << hp2 << " " << hp3 << "\n";
	if (hp1 <= 0 && hp2 <= 0 && hp3 <= 0) return 0;
	hp1 = max(hp1, 0);
	hp2 = max(hp2, 0);
	hp3 = max(hp3, 0);
	
	int& ret = cache[hp1][hp2][hp3];
	if (ret != -1) return ret;
	ret = 60;
	
	for (int i = 0; i < 6; i++) {
		ret = min(ret, solve(hp1 - damage[i][0], hp2 - damage[i][1], hp3 - damage[i][2]) + 1);
	}
	
	return ret;
}

int main(void) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> N;
    
	memset(cache, -1, sizeof(cache));
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	cout << solve(arr[1], arr[2], arr[3]);
	
	return 0;
}