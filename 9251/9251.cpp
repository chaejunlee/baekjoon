#include <bits/stdc++.h>
#define pi pair<int, int>
#define ll long long
#define PQ priority_queue
using namespace std;

int N = 0, M = 0, K = 0;
string s, t;
int dp[1001][1001] = {0};

int solve() {
    N = s.length();
    M = t.length();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int temp = dp[i - 1][j - 1];
            if (s[i - 1] == t[j - 1])
                temp++;
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), temp);
        }
    }
    return dp[N][M];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    cout << solve();
}