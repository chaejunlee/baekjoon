#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1025][1025] = {0};
int dp[1025][1025] = {0};

void solve() {
    int a, b, c, d;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        int res = dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];
        cout << res << "\n";
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    solve();
}