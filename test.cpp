#include <bits/stdc++.h>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define ll long long
#define PQ priority_queue
using namespace std;
bool smaller_second(pi a, pi b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
bool bigger_second(pi a, pi b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

// cmp
// going up: small < bigger (if small is small, then it comes faster)
// going down: small > bigger

int t = 0, N = 0, M = 0, K = 0;
string dp[101];

// 1 1 1 1 ( 1 )
// 1 2 1 1 ( 2 )

string addString(string a, string b) {
    int aL = a.length();
    int bL = b.length();
    string res;
    int adder = 0;
    for (int i = 0; i < min(aL, bL); i++) {
        int temp = adder + a.at(i) - '0' + b.at(i) - '0';
        adder = temp / 10;
        char d = temp % 10 + '0';
        res.push_back(d);
    }
    if (aL < bL) {
        for (int i = min(aL, bL); i < max(aL, bL); i++) {
            int temp = adder + b.at(i) - '0';
            adder = temp / 10;
            char d = temp % 10 + '0';
            res.push_back(d);
        }
    } else {
        for (int i = min(aL, bL); i < max(aL, bL); i++) {
            int temp = adder + a.at(i) - '0';
            adder = temp / 10;
            char d = temp % 10 + '0';
            res.push_back(d);
        }
    }
    if (adder) {
        char d = adder + '0';
        res.push_back(d);
    }
    return res;
}

void solve() {
    for (int i = 0; i <= K; i++) {
        dp[i] = "1";
    }
    for (int i = 1; i < N; i++) {
        for (int j = min(K, i); j >= 1; j--) {
            dp[j] = addString(dp[j], dp[j - 1]);
            //cout << dp[j] << " ";
        }
        //cout << "\n";
    }
    reverse(dp[K].begin(), dp[K].end());
    cout << dp[K];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    solve();
}