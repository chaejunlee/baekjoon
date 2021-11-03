#include <bits/stdc++.h>
using namespace std;

int N;
int block[51];
int cache[51][500001][2];

// 블록을 쌓아 두 개의 탑을 만든다.
// 두 개의 탑의 높이가 같아야 한다.
// 모든 블록을 쓸 필요는 없다. 하지만 1개 이상은 쌓아야 한다.
// 리턴 값은 만들 수 있는 탑의 높이의 최댓값.

/*
 * 1. 완전 탐색
int solve(k, arr)
    if (k == N)
        
**/
int solve(int n, int diff, int start) {
    if (n == N) {
        if (start && diff == 250000) {
            return 0;
        }
        return -5000000;
    }
    if (diff > 500000 || diff < 0) return -5000000;
    
    int& ret = cache[n][diff][start];
    if (ret != -1) return ret;
    ret = -5000000;
    
    int leftTower, rightTower, skip;

    leftTower = solve(n + 1, diff + block[n], 1) + block[n];
    rightTower = solve(n + 1, diff - block[n], 1);
    
    ret = max(ret, leftTower);
    ret = max(ret, rightTower);
    
    skip = solve(n + 1, diff, start);
    ret = max(ret, skip);
    
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> block[i];
    }
    memset(cache, -1, sizeof(cache));
    
    int ret = solve(0, 250000, 0);
    if (ret < 0) cout << "-1\n";
    else cout << ret << "\n";
    
    
    return 0;
}
