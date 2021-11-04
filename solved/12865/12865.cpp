#include <bits/stdc++.h>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define ll long long
#define PQ priority_queue
using namespace std;

int t = 0, N = 0, M = 0, K = 0;
vpi v;
int dp[100][100001] = {0};

void solve() {
    int W, V;
    for (int i = 1; i <= N; i++) {
        cin >> W >> V;
        v.push_back(make_pair(W, V));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i == 0) {
                if (v[i].first <= j) {
                    dp[i][j] = v[i].second;
                }
                continue;
            }
            if (v[i].first <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i].second + dp[i - 1][j - v[i].first]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N - 1][K];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    solve();
}