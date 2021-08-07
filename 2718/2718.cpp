#include <bits/stdc++.h>

using namespace std;

int t = 0, N = 0, M = 0, K = 0;
/*
xx  
xx 
xx 
xx
0000 = 0

xx 
xx 
ox  
ox  
0011 = 3

xx 
ox 
ox 
xx 
0110 = 6

ox 
xx 
xx 
ox 
1001 = 9

ox
ox
xx 
xx 
1100 = 12

*/
int cache[1000][(1<<4)];

int solve(int n, int state) {
    if (n < 0) return 0;
    if (n == 0) {
        if (state == 0)
            return 1;
    }
	
	int& ret = cache[n][state];
	if (ret != -1) return ret;
	ret = 0;
	
	if (state == 0) {
	    ret = solve(n - 1, 0) + solve(n - 2, 0) + solve(n - 1, 3) + solve(n - 1, 6) + solve(n - 1, 12);
	}
	if (state == 3) {
	    ret = solve(n - 1, 0) + solve(n - 1, 12);
	}
	if (state == 6) {
	    ret = solve(n - 1, 0) + solve(n - 1, 9);
	}
	if (state == 9) {
	    ret = solve(n - 1, 6);
	}
	if (state == 12) {
	    ret = solve(n - 1, 0) + solve(n - 1, 3);
	}
	
	return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    
	memset(cache, -1, sizeof(cache));
	while (T--) {
	    cin >> N;
	    cout << solve(N, 0) << "\n";
	}
	
	return 0;
}