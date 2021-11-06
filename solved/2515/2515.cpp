#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<pair<int, int>> painting;
long long cache[300001];

long long solve(int k) {
    if (k >= N) return 0ll;
    
    long long& ret = cache[k];
    if (ret != -1) return ret;
    ret = 0ll;
    
    int height = painting[k].first;
    
    
    int lo = k, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (painting[mid].first < height + S) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    //cout << k << " " << lo << "\n";
    ret = solve(k + 1);
    ret = max(ret, solve(lo) - painting[k].second);

    
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        painting.push_back({a, -b});
    }
    sort(painting.begin(), painting.end());
    //for (auto p : painting) cout << p.first << " " << p.second << "\n";
    
    memset(cache, -1, sizeof(cache));
    
    long long ret = 0;
    ret = max(ret, solve(0));
    
    cout << ret << "\n";
    
    
    return 0;
}

// 1 1 2 2 3 3 
