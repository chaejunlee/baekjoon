#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
int n;
int arr[1001];
int cache[1001][1001];

int solve(int left, int right) {
    if (left == right) return 0;
    
    int& ret = cache[left][right];
    if (ret != -1) return ret;
    ret = 0;
    
    int M = 0, m = 10001;
    for (int i = left; i <= right; i++) {
        M = max(M, arr[i]);
        m = min(m, arr[i]);
    }
    ret = M - m;
    
    for (int i = left; i < right; i++) {
        ret = max(ret, solve(left, i) + solve(i + 1, right));
    }
    
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(1, n);
    
    return 0;
}